SELECT DISTINCT maker, speed
FROM laptop JOIN product
ON laptop.model = product.model
WHERE hd >= 10
