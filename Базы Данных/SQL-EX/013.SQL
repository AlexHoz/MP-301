SELECT AVG(speed)
FROM Product JOIN PC
ON Product.model = PC.model
WHERE maker = 'A'
