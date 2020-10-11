SELECT DISTINCT Q.country, CONVERT(NUMERIC(6,2), (SUM((Q.bore * Q.bore * Q.bore) * Q.cnt) / SUM(Q.cnt) / 2)) weight
FROM (SELECT c.country, c.class, c.bore, (
          SELECT (COUNT(name)+
                 (SELECT COUNT(T.ship) 
                  FROM (SELECT DISTINCT ship 
                        FROM Outcomes 
                        WHERE ship = c.class AND ship NOT IN (SELECT name FROM Ships)) T )) cnt       
          FROM Ships 
          WHERE class = c.class) cnt
     FROM classes c) Q
WHERE Q.cnt > 0
GROUP BY Q.country