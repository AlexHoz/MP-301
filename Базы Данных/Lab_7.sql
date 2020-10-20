--Задание 6
SELECT DISTINCT maker, speed
FROM product JOIN laptop
ON product.model = laptop.model
WHERE hd >= 10

--Задание 14
SELECT classes.class, name, country
FROM classes
JOIN ships
ON classes.class = ships.class
WHERE classes.numGuns >= 10

--Задание 16
SELECT DISTINCT A.model AS model_1, B.model AS model_2, A.speed, A.ram 
FROM pc AS A, pc B
WHERE A.speed = B.speed AND A.ram = B.ram AND A.model > B.model

--Задание 18
SELECT DISTINCT maker, price
FROM printer INNER JOIN product ON printer.model = product.model AND color = 'y'
WHERE price = (SELECT MIN(price) FROM printer WHERE color = 'y')

--Задание 18(2)
SELECT DISTINCT maker,price
FROM PRODUCT JOIN Printer on Product.model=Printer.model
WHERE price = (SELECT MIN(price) AS Mon_price FROM Printer WHERE color = 'y')
AND color = 'y'

--Задание 19
SELECT maker, AVG(screen) AS avg
FROM Product p JOIN Laptop l ON p.model = l.model
Group by maker

--Задание 21
SELECT maker, MAX(price) as max_price
FROM Product JOIN PC
ON Product.model = Pc.model
GROUP BY maker

--Задание 27
SELECT maker, AVG(hd) AS hd
FROM PC INNER JOIN Product ON PC.model = Product.model
  WHERE maker IN (SELECT maker
  FROM Product 
  WHERE type = 'Printer'
  )
GROUP BY maker

--Задание 73
SELECT DISTINCT Classes.country, Battles.name
FROM Battles, Classes
EXCEPT 
SELECT Classes.country, Outcomes.battle
FROM Outcomes LEFT JOIN Ships ON Ships.name = Outcomes.ship LEFT JOIN Classes ON Outcomes.ship = Classes.class OR Ships.class = Classes.class
WHERE Classes.country IS NOT NULL
GROUP BY Classes.country, Outcomes.battle



--Дополнительные задания из лабораторной
--1.2
SELECT DISTINCT A.model AS model_1, B.model AS model_2, A.price
FROM printer AS A, printer B
WHERE A.price = B.price AND A.model < B.model
