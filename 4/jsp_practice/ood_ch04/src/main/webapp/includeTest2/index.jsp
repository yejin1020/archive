<%-- 
    Document   : index
    Created on : 2021. 3. 31., 오후 6:05:45
    Author     : 920
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>&lt;jsp:include&gt; 액션 예제</title>
    </head>
    <body>
        <jsp:include page= "header.jsp" />
        본문 내용입니다.
        <% request.setCharacterEncoding("UTF-8");%>
        <%-- request.setCharacterEncoding("UTF-8");--%>
        <jsp:include page = "footer.jsp"> 
          <jsp:param name = "date" value = "<%= new java.util.Date() %>"/>
          <jsp:param name = "user" value = "홍길동"/>
        </jsp:include>
    </body>
</html>
