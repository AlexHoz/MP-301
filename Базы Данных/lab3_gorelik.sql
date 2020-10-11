-- 1.1(10)
SELECT DISTINCT model, price
  FROM Printer
 WHERE price = (SELECT MAX(price)
                   FROM Printer
                )
-- 1.2(17)
SELECT DISTINCT 'Laptop' as type, Laptop.model, Laptop.speed
  FROM Laptop 
 WHERE Laptop.speed < (SELECT MIN(speed)
                            FROM PC
                      )
-- 1.3
SELECT model, price
  FROM Printer
 WHERE color = 'y' AND price = (SELECT MIN(price)
                                  FROM Printer
                                 WHERE color = 'y')
-- 2.1(9)
SELECT DISTINCT maker 
  FROM Product
 WHERE model IN (SELECT model
                   FROM PC
                  WHERE speed >=450
                )
-- 2.2(13)
SELECT AVG(speed) as Avg_speed
  FROM PC
 WHERE model IN (SELECT model
                   FROM Product
                  WHERE maker = 'A'
                )
-- 2.3(7)
SELECT model, price
  FROM (SELECT model, price
          FROM PC
         UNION
        SELECT model, price
          FROM Laptop
         UNION
        SELECT model, price
          FROM Printer
       ) AS models
 WHERE models.model in (SELECT model 
                          FROM Product 
                         WHERE maker = 'B'
                       )
-- 2.4(23)
SELECT maker 
  FROM Product JOIN PC
    ON Product.model = PC.model
 WHERE (PC.speed >= 750)
INTERSECT
SELECT maker 
  FROM Product JOIN Laptop 
    ON Product.model = Laptop.model
 WHERE (Laptop.speed >= 750)
-- 2.5(26)
SELECT AVG(price) as AVG_price 
  FROM (SELECT price, code, 'PC' as type 
          FROM PC 
         WHERE model IN (SELECT model
                            FROM Product
                           WHERE Product.maker = 'A')
         UNION 
        SELECT price, code, 'Laptop' as type 
          FROM Laptop
         WHERE model IN (SELECT model
                            FROM Product
                           WHERE Product.maker = 'A')
       ) as tmp
-- 2.6(8) 
SELECT DISTINCT maker
  FROM Product
 WHERE type = 'PC' 
   AND maker NOT IN (SELECT maker                                        
                       FROM Product                                       
                      WHERE type = 'Laptop')
-- 2.7(34)
SELECT DISTINCT name 
  FROM Ships
 WHERE launched >= 1922
   AND class IN (SELECT class 
                   FROM Classes 
                  WHERE type = 'bb' AND displacement > 35000)
-- 2.8(36)
SELECT name
  FROM Ships
 WHERE name = class
 UNION
SELECT ship
  FROM Outcomes
 WHERE ship IN (SELECT class
                  FROM Classes)
-- 2.9.1
SELECT model
  FROM PC
-- 2.9.2
SELECT model
  FROM Product
 WHERE type = 'pc'
   AND model NOT IN (SELECT model
                       FROM PC)
-- 2.9.3(80)
SELECT maker
  FROM Product
EXCEPT
SELECT maker
  FROM Product
 WHERE type = 'pc'
   AND model NOT IN (SELECT model
                       FROM PC)