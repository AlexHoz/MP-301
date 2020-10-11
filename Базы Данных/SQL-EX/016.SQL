SELECT DISTINCT a.model, b.model, a.speed, a.RAM
FROM pc AS  a, pc AS b
WHERE a.ram = b.ram and a.speed = b.speed and a.model > b.model
