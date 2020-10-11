SELECT name
FROM Ships inner join classes on ships.class = Classes.class
WHERE bore = 16
UNION
SELECT ship
FROM Outcomes inner join classes on outcomes.ship = Classes.class
WHERE bore = 16
