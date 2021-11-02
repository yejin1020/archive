<%-- 
    Document   : index
    Created on : 2021. 3. 31., 오후 7:44:21
    Author     : 920
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>&lt;jsp:forward&gt; 액션 예제</title>
    </head>
    <body>
        <%
            request.setCharacterEncoding("UTF-8");
            String user = request.getParameter("user");
            if ( user == null || user.equals("")) {
        %>
        
        사용자가 지정되지 않았습니다. 사용자 이름을 입력해 주시기 바랍니다.
        
        <form method ="POST" >
            이름 : <input type ="text" name = "user" value = "" />
            <input type="submit" value ="입력" />
        </form>
        
        <% }else {%>
        
        <jsp:forward page = "process.jsp"/>
        
        <% }%>

    </body>
</html>
