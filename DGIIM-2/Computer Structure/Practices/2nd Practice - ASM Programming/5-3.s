# SECCIÓN DE DATOS (.data, variables globales inicializadas)
.section .data
#ifndef TEST
#define TEST 19
#endif
	.macro linea
#if TEST==1
	.int -1 ,-1 ,-1, -1
#elif TEST==2
	.int 0x04000000, 0x04000000, 0x04000000, 0x04000000
#elif TEST==3
	.int 0x08000000, 0x08000000, 0x08000000, 0x08000000
#elif TEST==4
	.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif TEST==5
	.int 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff
#elif TEST==6
	.int 0x80000000, 0x80000000, 0x80000000, 0x80000000
#elif TEST==7
	.int 0xF0000000, 0xF0000000, 0xF0000000, 0xF0000000
#elif TEST==8
	.int 0xF8000000, 0xF8000000, 0xF8000000, 0xF8000000
#elif TEST==9
	.int 0xF7FFFFFF, 0xF7FFFFFF, 0xF7FFFFFF, 0xF7FFFFFF
#elif TEST==10
	.int 100000000, 100000000, 100000000, 100000000
#elif TEST==11
	.int 200000000, 200000000, 200000000, 200000000
#elif TEST==12
	.int 300000000, 300000000, 300000000, 300000000
#elif TEST==13
	.int 2000000000, 2000000000, 2000000000, 2000000000
#elif TEST==14
	.int 3000000000, 3000000000, 3000000000, 3000000000
#elif TEST==15
	.int -100000000, -100000000, -100000000, -100000000
#elif TEST==16
	.int -200000000, -200000000, -200000000, -200000000
#elif TEST==17
	.int -300000000, -200000000, -200000000, -200000000
#elif TEST==18
	.int -2000000000, -2000000000, -2000000000, -2000000000
#elif TEST==19
	.int -3000000000, -3000000000, -3000000000, -3000000000
#else
	.error "Definir TEST entre 1..19"
#endif
	.endm

lista: .irpc i,1234
		linea
	.endr
longlista:	.int   (.-lista)/4	# . = contador posiciones. Aritm.etiq.
resultado:	.quad   0

formato:
	.ascii "resultado \t = %18ld (sgn)\n"
	.ascii "\t\t = 0x%18lx (hex)\n"
	.asciz "\t\t = 0x %08x %08x\n"

# SECCIÓN DE CÓDIGO (.text, instrucciones máquina)
.section .text				# PROGRAMA PRINCIPAL
main: .global  main		# Programa principal si se usa C runtime

	call trabajar			# subrutina de usuario
	call imprim_C			# printf()  de libC
	call acabar_C			# exit()    de libC
	ret

trabajar:
	mov     $lista, %rbx	# dirección del array lista
	mov  longlista, %ecx	# número de elementos a sumar
	call suma				# == suma(&lista, longlista);
	mov  %eax, resultado	# salvar resultado
	mov  %edx, resultado+4	# incluye el acarreo
	ret

# SUBRUTINA: int suma(int* lista, int longlista);
# entrada:	1) %rbx = dirección inicio array
#			2) %ecx = número de elementos a sumar
# salida:	   %eax = resultado de la suma
suma:
	mov $0, %edi	# ponemos a 0 los registros a usar
	mov $0, %rsi
	mov $0, %r8d
bucle:
	mov (%rbx,%rsi,4), %eax		# mueve el siguiente elemento de la lista
	cltd						# extiende el signo de %eax
	add %eax, %edi				# suma %eax a %edi
	adc %edx, %r8d				# hace la suma con el acarreo
	inc %rsi					# incrementa el índice
	cmp %rsi,%rcx				# compara si son iguales
	jne bucle					# si no lo, vuelve a hacer el bucle

	mov %edi, %eax				# mueve la suma a %eax
	mov %r8d, %edx				# mueve el acarreo a %edx
	
	ret

 imprim_C:						# requiere libC, void 
	mov   $formato, %rdi		# traduce resultado a decimal/hex
	mov   resultado,%rsi		# versión libC de syscall __NR_write
	mov   resultado,%rdx		# ventaja: printf() con fmt "%u" / "%x"
	mov          $0,%eax		# varargin sin xmm
	call  printf				# == printf(formato, res, res);
	ret

 acabar_C:						# requiere libC, void exit(int status);
	mov  resultado, %edi		# status: código a retornar (la suma)
	call _exit					# ==  exit(resultado)
	ret
	
