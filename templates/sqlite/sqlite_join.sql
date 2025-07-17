	SELECT t1.cola, t1.colb, t2.colc 
	FROM t1 
	INNER JOIN t2
	WHERE t1.cola == t2.cola 
	AND ... 
	ORDER BY col DESC;
