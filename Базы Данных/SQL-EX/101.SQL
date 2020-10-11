WITH Tmp AS 
(
SELECT *,
	(SELECT COUNT (color)
	FROM Printer
	WHERE code <= P.code AND color = 'n') AS Q
FROM Printer AS P
)

SELECT
	code,
	model,
	color,
	type,
	price,
	(SELECT MAX(model) FROM Tmp WHERE Q = T.Q) AS max_model,
	(SELECT COUNT(DISTINCT Type) FROM Tmp WHERE Q = T.Q) AS distinct_types,
	(SELECT AVG(price) FROM Tmp WHERE Q = T.Q) AS avg_price
FROM Tmp AS T