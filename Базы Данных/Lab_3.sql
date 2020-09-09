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
FROM Product
WHERE model IN (SELECT model FROM PC WHERE speed >= 450)

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
SELECT AVG(price)
FROM
(
SELECT PC.price, PC.code, Product.type, Product.model
FROM PC JOIN Product ON (Product.model = PC.model 
			AND Product.type = 'PC' AND Product.maker = 'A')
UNION
SELECT Laptop.price,Laptop.code, Product.type, Product.model
FROM Laptop JOIN Product ON (Product.model = Laptop.model 
			AND Product.type = 'Laptop' AND Product.maker = 'A')
) AS NewTable

--Задание 34
SELECT DISTINCT name
FROM Ships, Classes 
WHERE Ships.launched >= 1922 AND Classes.type = 'bb' 
      AND Classes.displacement > 35000 AND Ships.class = Classes.class

--Задание 36
SELECT name
FROM Ships, Classes
WHERE Ships.name = Classes.class
UNION
SELECT ship
FROM Outcomes, Classes
WHERE Outcomes.ship = Classes.class

--Задание 80
SELECT DISTINCT maker 
FROM product  
WHERE maker NOT IN (
	SELECT maker 
	FROM product  
	WHERE model IN ( 
		SELECT model 
		FROM product 
		WHERE type = 'pc' 
		EXCEPT 
		SELECT model 
		FROM pc 
	) 
) 