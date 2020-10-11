SELECT Distinct battles.name
FROM (battles inner join outcomes on name = battle) inner join ships on ship = ships.name
WHERE class = 'Kongo'
