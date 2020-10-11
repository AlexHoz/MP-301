SELECT maker, AVG(hd) AS Avg_hd
FROM pc inner join Product on pc.model = product.model
GROUP BY maker
HAVING maker IN (SELECT maker FROM Product WHERE type = 'printer')
