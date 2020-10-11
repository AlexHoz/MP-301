SELECT name
FROM Ships, Classes 
WHERE Ships.class = Classes.class AND launched >= 1922 AND type = 'bb' AND displacement > 35000
