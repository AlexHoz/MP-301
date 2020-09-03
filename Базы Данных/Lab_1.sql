--Задание 1
SELECT model, speed, hd
FROM PC
WHERE price < 500

--Задание 2
SELECT DISTINCT maker
FROM Product
WHERE type = 'Printer'

--Задание 3
SELECT model, ram,screen
FROM Laptop
WHERE price > 1000

--Задание 4
SELECT DISTINCT code, model, color, type, price
FROM Printer 
WHERE color = 'y'

--Задание 5
SELECT DISTINCT model, speed, hd
FROM PC
WHERE (cd = '12x' OR cd = '24x') AND price < 600

--Задание 11
SELECT AVG(speed) 
FROM PC

--Задание 12
SELECT AVG(speed) 
FROM Laptop
WHERE price > 1000

--Задание 31
SELECT class, country
FROM Classes 
WHERE bore >= 16

--Задание 33
SELECT ship
FROM Outcomes 
WHERE battle = 'North Atlantic' AND result = 'sunk'

--Задание 42
SELECT ship, battle
FROM Outcomes 
WHERE result = 'sunk'
