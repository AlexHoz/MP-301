--Задание 37
SELECT class
  FROM (SELECT class, name
          FROM Ships
        UNION
        SELECT Outcomes.ship, Outcomes.ship
          FROM Outcomes, classes
         WHERE outcomes.ship = classes.class) as t1
 GROUP BY class
HAVING COUNT(name) = 1

--Задание 48
SELECT class
  FROM Ships
 WHERE name in (SELECT DISTINCT ship 
                  FROM outcomes 
                 WHERE result = 'sunk')
UNION 
SELECT ship
  FROM Outcomes
 WHERE result = 'sunk' AND ship IN (SELECT class FROM classes)
 
 --Задание 49
SELECT name
  FROM Ships
 WHERE class IN (SELECT class
                   FROM Classes 
                  WHERE bore = 16)
UNION
SELECT ship as name
  FROM Outcomes
 WHERE ship IN (SELECT class
                   FROM Classes 
                  WHERE bore = 16)

--Задание 50
SELECT DISTINCT battle
  FROM Outcomes
 WHERE Outcomes.ship IN (SELECT name
                           FROM Ships
                          WHERE class = 'Kongo')

--Задание 63
SELECT name
FROM passenger
WHERE id_psg
IN
(
	SELECT ID_psg
	FROM pass_in_trip
	GROUP BY ID_psg, place
	HAVING count(place) > 1
)

--Задание 74
SELECT Country, Class
  FROM Classes
 WHERE Country = 'Russia'
UNION
SELECT Country, Class
  FROM Classes
 WHERE NOT EXISTS (SELECT Country, Class
                     FROM Classes
                    WHERE Country = 'Russia')

--Задание 85
SELECT maker
  FROM (SELECT maker, MAX(type) AS type, COUNT(DISTINCT model) AS count_model
          FROM Product
         GROUP BY maker
        HAVING COUNT(DISTINCT type) = 1
       ) AS X
 WHERE (type = 'Printer') OR (count_model > 2 AND type = 'PC')

--Дополнительные задания из лабораторной
-- 1.2
SELECT *
  FROM utQ

SELECT * 
  FROM utV

SELECT *
  FROM utB
  
-- 1.3
SELECT * 
  FROM utQ 
 WHERE Q_ID IN (SELECT DISTINCT B_Q_ID
                  FROM utB)
                  
-- 1.4
SELECT * 
  FROM utQ 
 WHERE Q_ID NOT IN (SELECT DISTINCT B_Q_ID
                  FROM utB)
                  
-- 1.5
SELECT Q_NAME
  FROM utQ
WHERE Q_ID IN (SELECT B_Q_ID
                 FROM (SELECT B_Q_ID, SUM(B_VOL) AS total_paint
                         FROM utB
                        GROUP BY B_Q_ID) as sum_paint
                 WHERE total_paint = 765)
                 
-- 1.6
SELECT Q_NAME
  FROM utQ
WHERE Q_ID IN (SELECT B_Q_ID
                 FROM (SELECT B_Q_ID, COUNT(DISTINCT B_V_ID) AS count_paints
                         FROM utB
                        GROUP BY B_Q_ID) as paints
                WHERE count_paints > 3)
                
-- 1.7
SELECT Q_NAME
  FROM utQ
WHERE Q_ID IN (SELECT B_Q_ID
                 FROM (SELECT B_Q_ID, COUNT(B_V_ID) AS count_paints
                         FROM utB
                        GROUP BY B_Q_ID) as paints
                WHERE count_paints > 3)
                
-- 1.9
SELECT Q_NAME
  FROM utQ
 WHERE Q_ID IN (SELECT B_Q_ID
                  FROM (SELECT B_Q_ID, COUNT(B_V_ID) AS count_paints
                          FROM utB
                         GROUP BY B_Q_ID) as paints
                 WHERE count_paints > 3)
   AND Q_ID IN (SELECT B_Q_ID
                  FROM (SELECT B_Q_ID, COUNT(DISTINCT B_V_ID) AS different_paints
                          FROM utB
                         GROUP BY B_Q_ID) as paints
                 WHERE different_paints = 2)
                 
-- 1.10
SELECT Q_NAME
  FROM utQ
 WHERE Q_ID IN (SELECT B_Q_ID
                  FROM utB
                 WHERE B_V_ID IN (SELECT V_ID
                                    FROM utV
                                   WHERE V_COLOR = 'G')
               )
               
-- 1.11
SELECT Q_NAME
  FROM utQ
 WHERE Q_ID IN (SELECT B_Q_ID
                  FROM utB
                 WHERE B_V_ID IN (SELECT V_ID
                                    FROM utV
                                   WHERE V_COLOR = 'G')
 ) AND Q_ID NOT IN (SELECT B_Q_ID
                      FROM utB
                     WHERE B_V_ID IN (SELECT V_ID
                                        FROM utV
                                       WHERE V_COLOR = 'R')
                   )

-- 2.5
SELECT *
  FROM Passenger

SELECT *
  FROM Pass_in_trip

-- 2.7
SELECT DISTINCT name
  FROM Passenger
 WHERE ID_psg IN (SELECT ID_psg
                    FROM Pass_in_trip
                   WHERE trip_no IN (SELECT trip_no
                                       FROM Trip
                                      WHERE town_to = 'Rostov')
                 )
                 
-- 2.8
SELECT DISTINCT name
  FROM Passenger
 WHERE ID_psg IN (SELECT ID_psg
                    FROM Pass_in_trip
                   WHERE trip_no IN (SELECT trip_no
                                       FROM Trip
                                      WHERE town_to = 'Rostov')
                   GROUP BY ID_psg
                  HAVING COUNT(trip_no) > 1
                 )
