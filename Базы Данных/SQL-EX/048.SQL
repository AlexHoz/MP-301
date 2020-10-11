SELECT distinct classes.class
FROM ships left join classes on ships.class = classes.class
WHERE name in (SELECT distinct ship FROM outcomes WHERE result = 'sunk')
UNION 
SELECT distinct ship
FROM outcomes left join ships on ship = name
WHERE name is null and result = 'sunk' and ship IN (SELECT class FROM classes)
