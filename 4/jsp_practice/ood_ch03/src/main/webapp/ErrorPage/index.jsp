<%-- 
    Document   : index.jsp
    Created on : 2021. 3. 24., 오후 8:08:41
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>page 지시어의 오류 관련 속성 미사용 예제</title>
    </head>
    <body>
        <%= 5/0 %>
    </body>
</html>
