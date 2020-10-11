SELECT name, CAST (date - DATEPART(dd,date)+1 AS DATE), CAST (DATEADD(mm,1,date - DATEPART(dd,date) + 1) - 1 AS DATE) 
FROM battles
