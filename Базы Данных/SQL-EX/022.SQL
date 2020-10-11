SELECT speed, AVG(price) AS Avg_Price
FROM PC
GROUP BY speed
HAVING speed > 600
