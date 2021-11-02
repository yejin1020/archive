 <%-- 
    Document   : index
    Created on : 2021. 5. 16., 오후 4:59:31
    Author     : yejin
--%>


<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.net.URLEncoder" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<c:set value="D:/github/JSP_mavenWebMail_TeamProject/maven_webmail/target/maven_webmail-1.0-SNAPSHOT/WEB-INF/download/a/" var ="targetDirectory"/>
<jsp:useBean id="fileList" scope="page" class="cse.my_name.ood_ch07.file_download.beans.FileListBean"/>
<jsp:setProperty name="fileList" property="dirName" value="${targetDirectory}"/>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>파일 내려 받기 속동 향상 ver</title>
    </head>
    <body>
        <h1>파일 내려 받기 속동 향상 ver</h1>
        <hr/>
        원하는 파일 선책하세요<br/><br/>
    
        <form method="POST" action="DownloadServlet_fast.do">
            <c:forEach var="fileName" items="${fileList.relativeFileList}" > <!-- 보여지는 부분-->
                <input type ="radio" name="D1" value="${fileName}"/> ${fileName} <br>
            </c:forEach>
            <br/>
            <input type="hidden" name="dirName" value="${targetDirectory}"/>
            <input type="submit" value="내려 받기"/>
        </form>
    </body>
</html>
