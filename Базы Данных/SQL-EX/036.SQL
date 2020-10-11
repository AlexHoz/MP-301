SELECT DISTINCT ship
FROM Outcomes inner join classes ON Classes.class = Outcomes.ship
UNION
SELECT DISTINCT Ships.name
FROM Ships inner join classes ON Classes.class = Ships.name
