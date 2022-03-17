# SECCIÓN DE DATOS (.data, variables globales inicializadas)
.section .data
lista:		.int 0x0fffffff,0x0fffffff,0x0fffffff,0x0fffffff, 0x0fffffff,0x0fffffff,0x0fffffff,0x0fffffff, 0x0fffffff,0x0fffffff,0x0fffffff,0x0fffffff, 0x0fffffff,0x0fffffff,0x0fffffff,0x0fffffff
longlista:	.int   (.-lista)/4	# . = contador posiciones. Aritm.etiq.
resultado:	.quad   0

formato: 	.asciz	"suma = %lu = 0x%lx hex\n"	# fmt para printf() libC

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
	mov  $0, %edx			# poner a 0 acarreo
	mov  $0, %eax			# poner a 0 acumulador
	mov  $0, %rsi			# poner a 0 índice
 bucle:
    add  (%rbx,%rsi,4), %eax	# acumular i-ésimo elemento
    jnc	  incremento			# hace el incremento
    inc	  %edx					# si no hay acarreo, se salta este inc
 incremento:
    inc   %rsi					# incrementar índice
    cmp   %rsi,%rcx				# comparar la longitud
    jne    bucle				# si no iguales, seguir acumulando
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



