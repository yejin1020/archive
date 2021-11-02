<%-- 
    Document   : show_sum
    Created on : 2021. 3. 31., 오후 5:55:10
    Author     : 920
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<jsp:useBean id="sum" scope="page" class="cse.my_name.ood_ch04.beans.SumBean" />
<jsp:setProperty name="sum" property ="n"/>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Beans 사용 예제</title>
    </head>
    <body>
        <% sum.calculate();%>
        계산 결과 1 : <jsp:getProperty name="sum" property="result"/> <br/>
        계산 결과 2: <%= sum.getResult()%> <br />
        계산 결과 3 : ${sum.result}
    </body>
</html>
