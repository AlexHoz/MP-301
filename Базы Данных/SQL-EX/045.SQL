SELECT Distinct name
FROM Ships
WHERE name LIKE '% % %'
Union
SELECT Distinct ship
FROM Outcomes
WHERE ship LIKE '% % %'
