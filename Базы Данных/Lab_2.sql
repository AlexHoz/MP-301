--Задание 38
SELECT DISTINCT country
FROM Classes
WHERE type = 'bb'
INTERSECT
SELECT DISTINCT country
FROM Classes
WHERE type = 'bc'

--Задание 8
SELECT DISTINCT maker
FROM Product
WHERE type = 'PC' AND 
      maker NOT IN (SELECT maker 
                    FROM Product 
                    WHERE type = 'Laptop'
                    )

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

--Задание 35 (%[^A-Za-z]%' - выбираем всё кроме букв,NOT LIKE - отрицаем всю выборку и остаются только буквы.
--Не совсем понимаю почему именно так)
SELECT DISTINCT model, type
FROM Product
WHERE model NOT LIKE '%[^A-Za-z]%' OR 
      model NOT LIKE '%[^0-9]%'
