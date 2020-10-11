--Задание 38
SELECT DISTINCT country
FROM Classes
WHERE type = 'bb'
INTERSECT
SELECT DISTINCT country
FROM Classes
WHERE type = 'bc'

--Задание 8
SELECT maker
  FROM Product
 WHERE type = 'PC'
EXCEPT 
SELECT maker                                        
  FROM Product                                       
 WHERE type = 'Laptop'

--Задание 44 (Почему-то, в таблице Ships не все корабли, поэтому нужно взять доп инфу из таблицы Outcomes)
SELECT DISTINCT name
FROM Ships
WHERE name LIKE 'R%'
UNION
SELECT DISTINCT ship
FROM Outcomes
WHERE ship LIKE 'R%'

--Задание 45
SELECT DISTINCT name
FROM Ships
WHERE name LIKE '% % %'
UNION
SELECT DISTINCT ship
FROM Outcomes
WHERE ship LIKE '% % %'

--Задание 35 (%[^A-Za-z]%' - выбираем всё кроме букв,NOT LIKE - отрицаем всю выборку и остаются только буквы.)
SELECT DISTINCT model, type
FROM Product
WHERE model NOT LIKE '%[^A-Za-z]%' OR 
      model NOT LIKE '%[^0-9]%'

--Дополнительные задания из лабораторной
-- 1.1
SELECT model, price
  FROM PC 
 UNION
SELECT model, price
  FROM Laptop

SELECT model, price
  FROM PC 
 UNION ALL
SELECT model, price
  FROM Laptop
  
-- 1.2
SELECT name as all_ships
  FROM Ships
 UNION 
SELECT ship
  FROM Outcomes
  
-- 2.1
SELECT model, speed, 'MHz' as speed_units, ram, 'Mb' as ram_units, hd, 
       'Gb' as hd_units, price, '$' as price_units
  FROM Laptop
  
-- 2.2
SELECT model, speed, 'MHz' as speed_units, ram * 1024 as ram_in_kb, 'Kb' as ram_units, hd, 
       'Gb' as hd_units, price, '$' as price_units
  FROM Laptop
  
-- 2.3
SELECT 'PC' as type, model, price 
  FROM PC
 UNION 
SELECT 'Laptop' as type, model, price
  FROM Laptop
 UNION
SELECT 'Printer' as type, model, price
  FROM Printer
  
-- 2.4
SELECT 'PC' as type, model, price 
  FROM PC
 WHERE price > 600
 UNION 
SELECT 'Laptop' as type, model, price
  FROM Laptop
 WHERE price > 600
 UNION
SELECT 'Printer' as type, model, price
  FROM Printer
 WHERE price > 600
 
-- 3.1
SELECT DISTINCT maker
  FROM Product
 WHERE type = 'Printer'
 ORDER BY maker DESC
 
-- 3.2
SELECT model, ram, screen
  FROM Laptop
 WHERE price > 1000
 ORDER BY ram DESC, model
 
-- 3.3
SELECT model, speed, hd
FROM PC
WHERE price < 600 AND (cd = '12x' OR cd = '24x')
ORDER BY cd DESC, hd DESC

-- 3.4 
SELECT model, speed, hd
  FROM PC
 WHERE price < 500
ORDER BY hd, cd DESC

-- 4.1
SELECT * 
  FROM Printer
 WHERE type != 'Jet'
 
-- 4.2
SELECT *
  FROM Printer
 WHERE price >= 150 AND price <= 300
 
-- 4.3
SELECT * 
  FROM Printer
 WHERE type != 'Jet' AND price >= 150 AND price <= 300
 
-- 4.4
SELECT * 
  FROM Printer
 WHERE type != 'Jet' OR (price >= 150 AND price <= 300)
 ORDER BY type, price
 
-- 4.5
SELECT * 
  FROM Printer
 WHERE type = 'Jet' AND price >= 150 AND price <= 300
 
-- 4.6
SELECT * 
  FROM Printer
 WHERE price < 200 OR price > 300
 
-- 5.1
SELECT name
  FROM Ships
 WHERE name LIKE 'R%'
UNION
SELECT ship
  FROM Outcomes
 WHERE ship LIKE 'R%'
 
-- 5.2
SELECT name
  FROM Ships
 WHERE name LIKE '% % %'
UNION
SELECT ship
  FROM Outcomes
 WHERE ship LIKE '% % %'
 
-- 5.3
SELECT name
  FROM Battles
 WHERE name LIKE '%[0-9]%'
 
SELECT name
  FROM Battles
WHERE name NOT LIKE '%[0-9]%'

SELECT name
  FROM Battles
WHERE name LIKE '%[aeiou]'

SELECT name
  FROM Battles
WHERE name NOT LIKE '%[aeiou]'

SELECT DISTINCT model, type
FROM Product
WHERE model LIKE '%[^0-9A-Za-z]%'

SELECT DISTINCT model, type
FROM Product
WHERE model NOT LIKE '%[^A-Za-z]%'

-- 5.4
SELECT DISTINCT model, type
FROM Product
WHERE model NOT LIKE '%[^A-Za-z]%' OR 
      model NOT LIKE '%[^0-9]%'
