<%-- 
    Document   : index
    Created on : 2021. 5. 19., 오후 9:31:23
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>jsp 초기화 방법</title>
    <style type ="text/css">
        body{
            margin: 50px 100px 50px 100px;
            background-color: rgb(220, 220, 220);
        }
        div {
            border: thin solid;
            margin-top: 10px; 
            margin-bottom: 10px;
            padding: 10px;
        }
        a:link, a:visited{
            color: navy;
        }
        a:hover {
            background-color: yellow;
        }
        
        p.usage { 
            margin: 50px; 
            border:solid 2px;
            border-color: gray;
            padding: 5px;
        }
        h1{
           border-style: groove; 
        }
    </style> 
    </head> 
    <body>
        <p>다음은 웹애플리케이션 초기화 예제입니다.</p>
        <div id="first">
            <!-- 첫번째 방법 -->
            <h1>1. ServletContext 객체 이용 방법</h1>
                컨텍스트 내에 있는 모든 서블릿에 사용 가능한 초기 값을 제공할 수 있습니다.
            <p class="usage">
                개는 
                <strong>
                    <%= getServletContext().getInitParameter("dog sound")%> 
                    <%= application.getInitParameter("dog sound") %>
                    ${initParam["dog sound"]} 
                </strong>
                짖습니다. 
            </p>
            
            web.xml에서 &lticontext-param &gt; 요소를 사용하여 웹 애플리케이션에 대한 초기 값을 설정합니다. 
            <br /> <br/>         
        </div>   
                 <div id="third">
            <h1>3. ServletContextListener 이용 방법</h1>
            컨텍스트 내에 있는 모든 서블릿에 사용 가능한 초기 값을 제공할 수 있습니다
            <p class="usage">
                새는 
                <strong>
                <%= getServletContext().getAttribute("새 울음소리")%>
                <%= application.getAttribute("새 울음소리") %>
                ${applicationScope["새 울음소리"]} 
                </strong>
                웁니다. 
            </p>

            web.xml에서 &lt;listener&gt; 요소를 사용하여 청취자 클래스를 등록해 주어야 합니다.
            ServletContextListener 인터페이스를 구현하는 청취자 클래스에서는 필요한 초기 값을 애트리뷰트로 설정합니다.
        </div>
        <div id="second">
      
            <h1>2. ServletConfig 객체 이용 방법</h1>
            특정 서블릿에 대한 초기 값을 제공할 수 있습니다.
            <p class="usage">
                <jsp:include page="myservlet.do"/>
            </p>                       
            web.xml에서 &lt;servlet&gt; 요소안에 있는 &lt;init-param&gt;
            요소를 사용하여 서블릿에 대한 초기 값을 설정합니다.
            <br/> <br/>
        </div> 
       
                
    </body> 
</html>

   

