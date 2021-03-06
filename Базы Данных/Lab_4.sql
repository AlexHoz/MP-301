--Задание 15
SELECT hd
FROM PC
GROUP BY hd
HAVING COUNT(hd) > 1

--Задание 20
SELECT maker, COUNT(model)
FROM Product
WHERE type = 'PC'
GROUP BY maker
HAVING COUNT(model) >= 3

--Задание 22
SELECT speed, AVG(price)
FROM PC
WHERE speed > 600
GROUP BY speed

--Задание 28
SELECT COUNT(maker)
FROM (
SELECT maker
FROM Product
GROUP BY maker
HAVING COUNT(DISTINCT model) = 1
) AS NewTable

--Задание 40
SELECT maker, MAX(type)
FROM Product
GROUP BY maker
HAVING COUNT(DISTINCT type) = 1 AND COUNT(model) > 1

--Задание 144
SELECT maker
FROM product
WHERE model
IN (
	SELECT model FROM pc WHERE price
	IN (
		SELECT MAX(price) FROM pc
	)
   )
INTERSECT
SELECT maker
FROM product
WHERE model
IN (
	SELECT model FROM pc WHERE price 
	IN (
		SELECT MIN(price) FROM pc
	)
)

--Дополнительные задания из лабораторной
-- 1.2
SELECT maker, COUNT(model) as count_model
  FROM Product
 GROUP BY maker
 
-- 1.3
SELECT maker, count(DISTINCT type) as COUNT_type
  FROM Product
 GROUP BY maker
 
-- 1.4 
SELECT maker, count(DISTINCT type) as count_type, COUNT(model) as count_model
  FROM Product
 GROUP BY maker
 
-- 1.5
SELECT maker, type
  FROM Product
 GROUP BY maker, type
 ORDER BY maker
 
-- 1.6 
SELECT maker, MAX(type) as max_type
  FROM Product
 GROUP BY maker
 
-- 1.7
SELECT maker, MIN(type) as max_type
  FROM Product
 GROUP BY maker
 
-- 1.8
SELECT maker, type, COUNT(model) as COUNT_model
  FROM Product
 GROUP BY maker, type
 ORDER by maker
 
-- 2.1
SELECT hd, COUNT(model)
  FROM PC
 GROUP BY HD
 
-- 2.2
SELECT hd, COUNT(model)
  FROM PC
 GROUP BY HD
HAVING COUNT(model) > 1

-- 2.5
SELECT speed, AVG(price) as avg_price
  FROM PC
 GROUP BY speed
 
-- 2.6
SELECT speed, AVG(price) as avg_price, COUNT(model) as count_model, SUM(price) as sum_price
  FROM PC
 GROUP BY speed
 
-- 2.8
SELECT maker, COUNT(model) as count_model
  FROM Product
 GROUP BY maker
HAVING COUNT(model) > 1

-- 2.9
SELECT maker
  FROM Product
 GROUP BY maker
HAVING COUNT(DISTINCT type) = 1

-- 2.10
SELECT maker, MIN(type) as the_only_type
  FROM Product
 GROUP BY maker
HAVING COUNT(DISTINCT type) = 1
