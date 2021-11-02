<%-- 
    Document   : index
    Created on : 2021. 3. 24., 오후 8:15:40
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>IncludeTest 프로젝트</title>
    </head>
    <body>
        <%@include file="header.jspf" %>
        본문 내용이 들어갈 자리입니다.
        <jsp:directive.include file = "footer.jspf"/> -
    </body>
</html>
