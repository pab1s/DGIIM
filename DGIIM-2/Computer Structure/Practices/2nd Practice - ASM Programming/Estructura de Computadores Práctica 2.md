# Estructura de Computadores: Práctica 2

## Programación Ensamblador x86-64 Linux

### Pablo Olivares Martínez

#### **Ejercicio 5.1** - Sumar N enteros sin signo de 32 bits sobre dos registros de 32 bits usando uno de ellos como acumulador de acarreos (N≈16).

Primero, realicemos la elaboración del programa:

```assembly
# SECCIÓN DE DATOS (.data, variables globales inicializadas)
.section .data
lista:		.int 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
longlista:	.int   (.-lista)/4	# . = contador posiciones. Aritm.etiq.
resultado:	.quad   0

# SECCIÓN DE CÓDIGO (.text, instrucciones máquina)
.section .text				# PROGRAMA PRINCIPAL
_start: .global _start		# Programa principal

	call trabajar			# subrutina de usuario
	call acabar_L			# finaliza el programa
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
    jnc	  incremento			# 
    inc	  %edx					# 
 incremento:
    inc   %rsi					# incrementar índice
    cmp   %rsi,%rcx				# comparar con longitud
    jne    bucle				# si no iguales, seguir acumulando
	ret

acabar_L:
	mov        $60, %rax
	mov  resultado, %edi
	syscall			# == _exit(resultado)
	ret

```

Para compilarlo, escribamos el siguiente comando en bash:

```bash
gcc -no-pie -nostartfiles 5-1.s -o 5-1
```

Tras la compilación y ejecución del programa obtendremos esto, donde 16 es la solución y es correcta:

![image-20201029205121488](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029205121488.png)

A continuación, modifiquemos los valores de la lista para probar si el algoritmo es correcto para distintas pruebas donde si que haya acarreo:

```assembly
.section .data
lista:		.int 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000,0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000
longlista:	.int (.-lista)/4
```

![image-20201029205401096](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029205401096.png)

Como hemos podido ver, al probar con el valor 0x1000 0000 nos damos cuenta que la solución no es correcta. Este valor es el primero que hace uso del acarreo, por ello si probáramos el anterior (0x0fff ffff), debería de ser una operación correcta:

```assembly
.section .data
lista:		.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
longlista:	.int (.-lista)/4
```

![image-20201029205605720](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029205605720.png)

Sin embargo, al obtener el resultado vemos que no es correcto. Si depuramos el programa con gdb, nos damos cuenta rápidamente de que el valor que debería devolver lo calcula correctamente (0xffff fff0), estando el problema en la impresión del valor. Por ello, vamos a modificar el programa para poder usar la impresión de *libC* y así solucionar este problema. Además le añadiremos un formato de salida:

```assembly
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

```

Compilamos el programa y lo ejecutamos:

```bash
gcc -no-pie 5-1.s -o 5-1
```

![image-20201029204045244](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029204045244.png)

Como hemos podido ver, este cambio ha solucionado el problema. Ahora veamos el anterior ejemplo y otro más para mostrar el correcto funcionamiento de acarreo:

```assembly
.section .data
lista:		.int 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000
longlista:	.int (.-lista)/4
resultado: .quad 0
formato: .asciz "suma = %lu = 0x%lx hex\n"
```

![image-20201028203213912](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028203213912.png)

```assembly
.section .data
lista:		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
longlista:	.int (.-lista)/4
resultado: .quad 0
formato: .asciz "suma = %lu = 0x%lx hex\n"
```

![image-20201029213818794](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029213818794.png)

Efectivamente, estos son los resultados esperados.



#### **Ejercicio 5.2 **- Sumar N enteros sin signo de 32 bits sobre dos registros de 32 bits mediante extensión con ceros (N≈16).

Realicemos ahora el programa:

```assembly
# SECCIÓN DE DATOS (.data, variables globales inicializadas)
.section .data
lista:		.int 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
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
    adc	  $0, %edx				# añade el acarreo
    inc	  %rsi					# incrementa el índice
	cmp   %rsi, %rcx			# compara si son iguales
	jne   bucle					# si no lo son, vuelve al bucle
	
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

```

Comprobemos si funciona con varios ejemplos con y sin acarreo:

![image-20201028210736930](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028210736930.png)

```assembly
.section .data
lista:		.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
longlista:	.int (.-lista)/4
```

![image-20201028210918486](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028210918486.png)

```assembly
.section .data
lista: 		.int 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000
longlista:	.int   (.-lista)/4
```

![image-20201028211846799](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028211846799.png)

```assembly
.section .data
lista: 		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
longlista:	.int   (.-lista)/4
```

![image-20201028212321902](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028212321902.png)

Como hemos podido comprobar, todos los ejemplos funcionan correctamente. Sin embargo, estar probando constantemente distintas listas de esta forma es muy ineficiente. Por ello, vamos a crear un script y una batería de tests las cuales se van a encargar de hacer las pruebas de golpe y ahorrándonos mucho tiempo:

```bash
for i in $(seq 1 8); do
  rm 5-2
  gcc -x assembler-with-cpp -D TEST=$i -no-pie $1 -o 5-2
  printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./5-2
done
```

```assembly
.section .data
#ifndef TEST
#define TEST 8
#endif
	.macro linea
#if TEST==1
	.int 1,1,1,1
#elif TEST==2
	.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
#elif TEST==3
	.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif TEST==4
	.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
#elif TEST==5
	.int -1, -1, -1, -1
#elif TEST==6
	.int 200000000, 200000000, 200000000, 200000000
#elif TEST==7
	.int 300000000, 300000000, 300000000, 300000000
#elif TEST==8
	.int 5000000000, 5000000000, 5000000000, 5000000000
#else
	.error "Definir TEST entre 1..8"
#endif
	.endm

lista: .irpc i,1234
		linea
		.endr
longlista:	.int   (.-lista)/4	# . = contador posiciones. Aritm.etiq.
resultado:	.quad   0

formato:
	.ascii "resultado \t = %18lu (uns)\n"
	.ascii "\t\t = 0x%18lx (hex)\n"
	.asciz "\t\t = 0x %08x %08x\n"
```

Se implementaría de esta forma y para probarlo, bastaría con ejecutar el script:

```assembly
./run_tests.sh
```

![image-20201028223311001](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201028223311001.png)

Como podemos observar, todo ha funcionado correctamente. No obstante, no vendría mal resaltar ese aviso, que nos muestra que se han tenido que truncar números ya que no cabían en un registro de 32 bits. Además de que el TEST05 es incorrecto, pues es con números negativos, pero es un caso que solucionaremos en el siguiente apartado.



#### **Ejercicio 5.3** - Sumar N enteros con signo de 32 bits sobre dos registros de 32 bits (mediante extensión de signo, naturalmente) (N≈16).

Realizamos el programa y modifiquemos el script para los nuevos tests:

```assembly
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
```

```bash
for i in $(seq 1 19); do
rm 5-3;
gcc -x assembler-with-cpp -D TEST=$i 5-3.s -no-pie -o 5-3;
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./5-3;
done
```

![image-20201030200318726](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201030200318726.png)

![image-20201030200340657](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201030200340657.png)

Todo ha salido correctamente y como podemos ver, soluciona el problema que tenía el programa del 5.2. Observar que el TEST14 sale un resultado erróneo por desbordamiento.

#### **Ejercicio 5.4** - Media y resto de N enteros con signo de 32 bits calculada usando registros de 32 bits (N≈16).

Hagamos de nuevo el programa y modifiquemos el script y los tests:

```assembly
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
	
```

```bash
for i in $(seq 1 19); do
rm 5-4;
gcc -x assembler-with-cpp -D TEST=$i 5-4.s -no-pie -o 5-4;
printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./5-4;
done
```

![image-20201029222358536](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029222358536.png)

![image-20201029222424081](/home/pablo/snap/typora/23/.config/Typora/typora-user-images/image-20201029222424081.png)

Todo ha salido como se esperaba. Cabe destacar que el resto puede ser negativo, siendo entonces una división truncada en vez de una de enteros, pues la división de enteros no acepta restos negativos.