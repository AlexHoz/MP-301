SELECT DISTINCT name
FROM Ships 
WHERE name LIKE 'R%'
UNION 
SELECT DISTINCT ship
FROM Outcomes
WHERE ship LIKE'R%'
