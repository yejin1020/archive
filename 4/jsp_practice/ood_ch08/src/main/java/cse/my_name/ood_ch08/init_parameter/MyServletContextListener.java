/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch08.init_parameter;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

/**
 * Web application lifecycle listener.
 *
 * @author yejin
 */
public class MyServletContextListener implements ServletContextListener {

    @Override
    public void contextInitialized(ServletContextEvent sce) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        ServletContext sc = sce.getServletContext();
        sc.setAttribute("새 울음소리", "짹짹");
    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {
        System.err.println("시스템이 종료됩니다.");
        
    }
}
