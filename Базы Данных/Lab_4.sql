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

