SELECT CAST
(             
CASE
WHEN (SELECT Sum(B_VOL) FROM utB) IS NULL 
THEN 0 
ELSE (SELECT Sum(B_VOL) FROM utB) 
END 
* 1.0     
/ (SELECT count(Q_ID) FROM utQ)
AS NUMERIC(5,2)
) avg_paint
