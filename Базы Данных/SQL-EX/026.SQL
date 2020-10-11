SELECT AVG(price)
FROM(
	SELECT price
	FROM PC inner join Product on pc.model = product.model
	WHERE maker = 'A'
	UNION ALL
	SELECT price
	FROM Laptop inner join Product on Laptop.model = product.model
	WHERE maker = 'A'
) AS pr
