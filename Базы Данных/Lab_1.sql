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

--Дополнительные задания из лабораторной
-- 1.1
SELECT * 
  FROM PC
  
-- 1.2
SELECT * 
  FROM Laptop
SELECT *
  FROM Printer
SELECT * 
  FROM Product
  
-- 1.3
SELECT *
  FROM Classes
SELECT *
  FROM Ships
SELECT *
  FROM Battles
SELECT *
  FROM Outcomes
  
-- 2.1
SELECT model
  FROM PC
  
-- 2.2
SELECT DISTINCT model
  FROM PC
  
-- 2.3
SELECT maker, model
  FROM Product
  
-- 4.1
SELECT MAX(speed)
  FROM Laptop
  
-- 4.2
SELECT MIN(speed)
  FROM Laptop
  
-- 4.3
SELECT AVG(speed)
  FROM Laptop
  
-- 4.4(11)
SELECT AVG(speed)
  FROM PC
  
-- 4.4(12)
SELECT AVG(speed)
  FROM Laptop
 WHERE price > 1000
 
 -- 5.1
 SELECT AVG(speed) as avg_speed
  FROM PC
  
-- 5.2 
SELECT ship as ship_sunk
  FROM Outcomes 
 WHERE battle = 'North Atlantic' 
   AND result = 'sunk'