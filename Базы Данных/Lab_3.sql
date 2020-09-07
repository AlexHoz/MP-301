--Задание 7
SELECT model, price
FROM (
	SELECT model, price
	FROM PC
	UNION
	SELECT model, price
	FROM Laptop
	UNION
	SELECT model, price
	FROM Printer
) AS NewTable
WHERE NewTable.model IN(
	SELECT model
	FROM Product
	WHERE maker = 'B'
)

--Задание 9
SELECT DISTINCT maker
FROM Product INNER JOIN 
PC ON PC.model = Product.model
WHERE PC.speed >= 450

--Задание 10
SELECT model, price
FROM Printer
WHERE price = (SELECT MAX(price) 
	       FROM Printer)

--Задание 13
SELECT AVG(speed)
FROM PC INNER JOIN
Product ON PC.model = Product.model
WHERE  Product.Maker = 'A'
--Или
SELECT AVG(speed)
FROM PC, Product
WHERE PC.model = Product.model AND Product.Maker = 'A'

--Задание 17
SELECT DISTINCT Product.type, Laptop.model, Laptop.speed
FROM Product, Laptop
WHERE type = 'Laptop' AND Laptop.speed < ALL (SELECT speed
 FROM PC
 )

--Задание 23
SELECT DISTINCT maker
FROM Product JOIN PC ON Product.model = PC.model
WHERE speed >= 750 AND maker IN
    (SELECT maker
    FROM Product JOIN Laptop ON Product.model = Laptop.model
    WHERE speed >= 750 )

--Задание 25
SELECT DISTINCT Maker
FROM Product
WHERE model IN 
    (
        SELECT model FROM PC WHERE ram = (SELECT MIN(ram) FROM PC) AND 
        speed = (SELECT MAX(speed) FROM PC WHERE ram = ( SELECT MIN(ram)FROM PC))
    )
    AND maker IN (SELECT maker FROM product WHERE type='Printer')

--Задание 26
--Задание 34
--Задание 36
--Задание 80