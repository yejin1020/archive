<%-- 
    Document   : show_error
    Created on : 2021. 3. 24., 오후 8:12:13
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page isErrorPage="true" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>오류 원인</title>
    </head>
    <body>
        오류 원인은 <%= exception.toString() %>
    </body>
</html>
