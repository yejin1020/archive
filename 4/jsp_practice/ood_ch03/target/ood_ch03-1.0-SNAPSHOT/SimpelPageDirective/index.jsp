<%-- 
    Document   : index.jsp
    Created on : 2021. 3. 24., 오후 7:48:18
    Author     : 920
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page  info="page 지시어 사용 방법을 보여줍니다."%>
<%@page import="java.util.Date"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>page 지시어 사용 방법</title>
    </head>
    <body>
       지금 시간은 <%= new Date() %>입니다.
    </body>
</html>
