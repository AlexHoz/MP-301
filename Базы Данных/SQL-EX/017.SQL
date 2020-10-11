SELECT DISTINCT Product.type, Laptop.model, Laptop.speed
FROM Laptop, PC, Product
WHERE Laptop.speed < ALL
	(SELECT speed
	FROM PC) AND Product.type = 'Laptop'
