/*CONSULTAS SQL*/
/*3.1 - Comprueba el resultado de la proyección. ¿Es este conforme a lo que se obtiene
 en el AR? */
SELECT
    ciudad
FROM
    proyecto;

/*NO, pues en el AR la proyección devuelve tuplas únicas, por lo que una forma de solucionarlo sería:*/
SELECT
    DISTINCT ciudad
FROM
    proyecto;

/*3.2 - Muestra los suministros realizados (tan solo los códigos de los componentes
 de una venta). ¿Es necesario utilizar DISTINCT?*/
SELECT
    DISTINCT codpj
FROM
    ventas;

/*3.3 - */
SELECT
    codpie
FROM
    pieza
WHERE
    (
        color = 'Gris'
        OR color = 'Rojo'
    )
    AND ciudad = 'Madrid';

/*3.4 - Encontrar todos los suministros cuya cantidad está entre 200 y 300, ambos
 inclusive. */
SELECT
    *
FROM
    ventas
WHERE
    200 <= cantidad
    AND cantidad <= 300;

/*3.5 - Mostrar las piezas que contengan la palabra tornillo con la t en
 mayúscula o en minúscula.*/
SELECT
    *
FROM
    piezas
WHERE
    nompie LIKE '_ornillo';

/*3.6 - Comprueba que no devuelve ninguna. Pero SÍ que hay!!!. Prueba a usar
 la función upper() comparando con ’VENTAS’ o la función lower() comparando con
 ’ventas’. */
/*¿POR QUÉ HAY DOS?*/
SELECT
    table_name
FROM
    ALL_TABLES
WHERE
    TABLE_NAME LIKE UPPER('%Ventas');

SELECT
    table_name
FROM
    ALL_TABLES
WHERE
    TABLE_NAME LIKE LOWER('%Ventas');

/*3.7 - Resolver la consulta del ejemplo 3.8 utilizando el operador intersección.*/
/*EJEMPLO 3.8*/
(
    SELECT
        DISTINCT ciudad
    FROM
        proveedor
    WHERE
        status > 2
)
MINUS
(
    SELECT
        DISTINCT ciudad
    FROM
        pieza
    WHERE
        codpie = 'P1'
);

(
    SELECT
        ciudad
    FROM
        proveedor
    WHERE
        status > 2
)
INTERSECT
(
    SELECT
        ciudad
    FROM
        pieza
    WHERE
        codpie <> 'P1'
);

/*3.8 - Encontrar los códigos de aquellos proyectos a los que sólo abastece ’S1’. */
(
    SELECT
        codpj
    FROM
        ventas
    WHERE
        codpro = 'S1'
)
MINUS
(
    SELECT
        codpj
    FROM
        ventas
    WHERE
        codpro <> 'S1'
);

/*3.9 - Mostrar todas las ciudades de la base de datos. Utilizar UNION. */
SELECT
    ciudad
FROM
    proyecto
UNION
SELECT
    ciudad
FROM
    pieza
UNION
SELECT
    ciudad
FROM
    proveedor;

/*3.10 - Mostrar todas las ciudades de la base de datos. Utilizar UNION ALL */
SELECT
    ciudad
FROM
    proyecto
UNION
ALL
SELECT
    ciudad
FROM
    pieza
UNION
ALL
SELECT
    ciudad
FROM
    proveedor;

/*3.11 - Comprueba cuántas tuplas resultan del producto cartesiano aplicado a ventas
 y proveedor. */
SELECT
    *
FROM
    ventas,
    proveedor;

/*EJERCICIO 3.12: Ternas que son de la misma ciudad pero que hayan
 realizdado alguna venta*/
SELECT
    codpro,
    codpie,
    codpj
FROM
    ventas
INTERSECT
SELECT
    DISTINCT codpro,
    codpie,
    codpj
FROM
    proveedor,
    pieza,
    proyecto
WHERE
    proveedor.ciudad = pieza.ciudad
    AND proveedor.ciudad = proyecto.ciudad
    AND pieza.ciudad = proyecto.ciudad;

/*EJERCICIO 3.13: Encontrar las parejas de proveedores que no viven
 en la misma ciudad*/
SELECT
    p.codpro,
    p.ciudad,
    s.codpro,
    s.ciudad
FROM
    proveedor p,
    proveedor s
WHERE
    p.ciudad != s.ciudad
    AND (p.codpro < s.codpro);

/*EJERCICIO 3.14: Encuentra las piezas con máximo peso*/
SELECT
    peso
FROM
    pieza
MINUS
(
    SELECT
        p1.peso
    FROM
        pieza p1,
        pieza p2
    WHERE
        p1.codpie <> p2.codpie
        AND p1.peso < p2.peso
);

/*3.15 - Mostrar las piezas vendidas por los proveedores de
 Madrid*/
SELECT
    DISTINCT codpie
FROM
    ventas NATURAL
    JOIN (
        SELECT
            codpro
        FROM
            proveedor
        WHERE
            ciudad = 'Madrid'
    );

/*3.16 - Encuentra la ciudad y los códigos de las piezas suministradas a cualquier
 proyecto por un proveedor que está en la misma ciudad donde está el proyecto.*/
SELECT
    DISTINCT codpie,
    ciudad
FROM
    ventas NATURAL
    JOIN (
        pieza NATURAL
        JOIN proyecto NATURAL
        JOIN proveedor
    );

/*3.17 - Comprobar la salida de la consulta anterior sin la cláusula ORDER BY.*/
SELECT
    nompro
FROM
    proveedor
ORDER BY
    nompro;

SELECT
    nompro
FROM
    proveedor;

/*3.18 - Listar las ventas ordenadas por cantidad, si algunas ventas coinciden en la
 cantidad se ordenan en función de la fecha de manera descendente. */
SELECT
    *
FROM
    ventas
ORDER BY
    cantidad,
    fecha DESC;

/*3.19 - Mostrar las piezas vendidas por los proveedores de Madrid. (Fragmentando
 la consulta con ayuda del operador IN.) Compara la solución con la del ejercicio 3.15. */
SELECT
    DISTINCT codpie
FROM
    ventas
WHERE
    codpro IN (
        SELECT
            codpro
        FROM
            proveedor
        WHERE
            ciudad = 'Madrid'
    );

/*3.20 - Encuentra los proyectos que están en una ciudad donde se fabrica alguna
 pieza. */
SELECT
    *
FROM
    proyecto
WHERE
    ciudad IN (
        SELECT
            ciudad
        FROM
            pieza
    );

/*3.21 - Encuentra los códigos de aquellos proyectos que no utilizan ninguna pieza
 roja que esté suministrada por un proveedor de Londres. */
/*3.21 - Encuentra los códigos de aquellos proyectos que no utilizan ninguna pieza
 roja que esté suministrada por un proveedor de Londres. */
SELECT
    DISTINCT codpj
FROM
    ventas NATURAL
    JOIN (
        SELECT
            *
        FROM
            (
                SELECT
                    DISTINCT codpie
                FROM
                    pieza
                WHERE
                    color <> 'Rojo'
            ),
            (
                SELECT
                    DISTINCT codpro
                FROM
                    proveedor
                WHERE
                    ciudad <> 'Londres'
            )
    );

/*3.22 - Muestra el código de las piezas cuyo peso es mayor que el peso de cualquier
 ’tornillo’. */
SELECT
    codpie
FROM
    pieza
WHERE
    peso > ANY (
        SELECT
            peso
        FROM
            pieza
        WHERE
            nompie LIKE 'Tornillo%'
    );

/*3.23 - Encuentra las piezas con peso máximo. Compara esta solución con la obtenida
 en el ejercicio 3.14 */
SELECT
    *
FROM
    pieza
WHERE
    peso >= ALL (
        SELECT
            peso
        FROM
            pieza
    );

/*3.24 - Encontrar los códigos de las piezas suministradas a todos los proyectos
 localizados en Londres. */
SELECT
    codpie
FROM
    pieza
WHERE
    NOT EXISTS (
        (
            SELECT
                DISTINCT codpj
            FROM
                proyecto
            WHERE
                ciudad = 'Londres'
        )
        MINUS
        (
            SELECT
                codpj
            FROM
                ventas NATURAL
                JOIN (
                    SELECT
                        codpj
                    FROM
                        proyecto
                    WHERE
                        ciudad = 'Londres'
                )
            WHERE
                codpie = pieza.codpie
        )
    );

/*3.25 - Encontrar aquellos proveedores que envían piezas procedentes de todas las
 ciudades donde hay un proyecto. */
SELECT
    codpro
FROM
    proveedor
WHERE
    NOT EXISTS(
        SELECT
            codpie
        FROM
            pieza NATURAL
            JOIN (
                SELECT
                    ciudad
                FROM
                    proyecto
            )
        MINUS
        SELECT
            codpie
        FROM
            ventas
        WHERE
            codpro = proveedor.codpro
    );

/*3.26 - Encontrar el número de envíos con más de 1000 unidades. */
SELECT
    COUNT(*)
FROM
    ventas
WHERE
    cantidad > 1000;

/*3.27 - Mostrar el máximo peso. */
SELECT
    MAX(peso)
FROM
    pieza;

/*3.28 - Mostrar el código de la pieza de máximo peso. */
SELECT
    codpie
FROM
    pieza
WHERE
    peso >= (
        SELECT
            MAX(peso)
        FROM
            pieza
    );

/*3.29 - Comprueba si la siguiente sentencia resuelve el ejercicio anterior. */
/*RESPUESTA: NO porque */
SELECT
    codpie,
    MAX(peso)
FROM
    pieza;

/*3.30 - Muestra los códigos de proveedores que han hecho 
 más de 3 envíos diferentes. */
SELECT
    codpro
FROM
    ventas
GROUP BY
    codpro
HAVING
    COUNT(*) > 3;

SELECT
    codpro
FROM
    (
        SELECT
            codpro,
            COUNT(*) AS cuenta
        FROM
            ventas
        GROUP BY
            codpro
    )
WHERE
    cuenta > 3;

SELECT
    codpro
FROM
    proveedor
WHERE
    (
        SELECT
            COUNT(*)
        FROM
            ventas
        WHERE
            ventas.codpro = proveedor.codpro
    ) > 3;

/*3.31 - Mostrar la media de las cantidades vendidas por cada código de pieza junto
 con su nombre.*/
SELECT
    codpie,
    nompie,
    ROUND(AVG(cantidad))
FROM
    (
        ventas NATURAL
        JOIN pieza
    )
GROUP BY
    codpie,
    nompie;

/*3.32 - Encontrar la cantidad media de ventas de la pieza ’P1’ realizadas por cada
 proveedor. */
SELECT
    codpro,
    AVG(cantidad)
FROM
    (
        SELECT
            *
        FROM
            ventas
        WHERE
            codpie = 'P1'
    )
GROUP BY
    codpro;

/*3.33 - Encontrar la cantidad total de cada pieza enviada a cada proyecto. */
SELECT
    codpie,
    codpj,
    SUM(cantidad)
FROM
    ventas
GROUP BY
    codpie,
    codpj;

/*3.34 - Comprueba si es correcta la solución anterior. */
/*CREO QUE ES CORRECTO*/
SELECT
    v.codpro,
    v.codpj,
    j.nompj,
    AVG(v.cantidad)
FROM
    ventas v,
    proyecto j
WHERE
    v.codpj = j.codpj
GROUP BY
    v.codpj,
    j.nompj,
    v.codpro;

SELECT
    codpro,
    codpj,
    nompj,
    AVG(cantidad)
FROM
    (
        ventas NATURAL
        JOIN proyecto
    )
GROUP BY
    codpj,
    nompj,
    codpro;

/*3.35 - Mostrar los nombres de proveedores tales que el total de sus ventas superen
 la cantidad de 1000 unidades. */
SELECT
    nompro,
    SUM(cantidad)
FROM
    (
        ventas NATURAL
        JOIN proveedor
    )
GROUP BY
    nompro
HAVING
    SUM(cantidad) > 1000;

/*3.36 - Mostrar la pieza que más se ha vendido en total. */
SELECT
    codpie,
    SUM(cantidad)
FROM
    ventas
GROUP BY
    codpie
HAVING
    SUM(cantidad) >= (
        SELECT
            MAX(SUM(cantidad))
        FROM
            ventas
        GROUP BY
            codpie
    );

/*3.37 - Comprueba que no funciona correctamente si las comparaciones de fechas se
 hacen con cadenas. */
SELECT
    *
FROM
    ventas
WHERE
    fecha BETWEEN TO_CHAR('01/01/2002', 'DD/MM/YYYY')
    AND TO_CHAR('31/12/2020', 'DD/MM/YYYY');

SELECT
    *
FROM
    ventas
WHERE
    fecha BETWEEN TO_DATE('01/01/2002', 'DD/MM/YYYY')
    AND TO_DATE('31/12/2020', 'DD/MM/YYYY');

/*3.38 - Encontrar la cantidad media de piezas suministradas cada mes. */
SELECT
    TO_CHAR(fecha, 'month'),
    AVG(cantidad)
FROM
    ventas
GROUP BY
    TO_CHAR(fecha, 'month');

/*3.39 - ¿Cuál es el nombre de la vista que tienes que consultar y qué campos te
 pueden interesar? */
/*La vista ALL_USERS y la vista DICTIONARY, para así buscar los índices a los que tenemos acceso.*/