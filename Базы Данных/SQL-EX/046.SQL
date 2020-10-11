SELECT DISTINCT ship, displacement, numguns
FROM classes LEFT JOIN ships ON classes.class=ships.class RIGHT JOIN outcomes ON classes.class=ship OR ships.name=ship
WHERE battle='Guadalcanal'
