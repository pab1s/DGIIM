# SECCIÓN DE DATOS (.data, variables globales inicializadas)
.section .data
#ifndef TEST
#define TEST 19
#endif
	.macro linea
#if TEST==1
	.int 1,2,1,2
#elif TEST==2
	.int -1,-2,-1,-2
#elif TEST==3
	.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
#elif TEST==4
	.int 0x80000000,0x80000000,0x80000000,0x80000000
#elif TEST==5
	.int 0xffffffff,0xffffffff,0xffffffff,0xffffffff
#elif TEST==6
	.int 2000000000,2000000000,2000000000,2000000000
#elif TEST==7
	.int 3000000000,3000000000,3000000000,3000000000
#elif TEST==8
	.int -2000000000,-2000000000,-2000000000,-2000000000
#elif TEST==9
	.int -3000000000,-3000000000,-3000000000,-3000000000
#elif TEST>=10 && TEST <=14
	.int 1,1,1,1
#elif TEST >= 15 && TEST<=19
	.int -1,-1,-1,-1
#else
	.error "Definir test"
#endif
	.endm

	.macro linea0
#if TEST>=1 && TEST<=9
	linea
#elif TEST==10
	.int 0,2,1,1
#elif TEST==11
	.int 1,2,1,1
#elif TEST==12
	.int 8,2,1,1
#elif TEST==13
	.int 15,2,1,1
#elif TEST==14
	.int 16,2,1,1
#elif TEST==15
	.int 0,-2,-1,-1
#elif TEST==16
	.int -1,-2,-1,-1
#elif TEST==17
	.int -8,-2,-1,-1
#elif TEST==18
	.int -15,-2,-1,-1
#elif TEST==19
	.int -16,-2,-1,-1#else
.error "Definir test"
#endif
	.endm

lista:		linea0
		.irpc i,123
			linea
		.endr

longlista:	.int   (.-lista)/4	# . = contador posiciones. Aritm.etiq.
media: .int 0
resto: .int 0

formato: .asciz "Media = %d = 0x%x hex\n Resto = %d = 0x%x hex\n"

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
	mov  %eax, media		# salvar media
	mov  %edx, resto		# salvar resto
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

	idiv %ecx					# hace la división entera con EDX:EAX

	ret

imprim_C:				# requiere libC
	mov $formato, %rdi	# mueven los datos a los registros de salida
	mov media, %esi
	mov resto, %ecx
	mov $0, %eax
	call printf
	ret
acabar_C:
	mov	media, %edi
	call exit			# ==exit(resultado)
	ret
	
	
