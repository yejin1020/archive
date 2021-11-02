/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch10;

import java.io.File;
import java.util.Date;
import java.util.Properties;
import javax.mail.Session;
import javax.mail.Address;
import javax.mail.Message;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import javax.mail.internet.MimeUtility;

/**
 *
 * @author yejin
 */
public class SimpleSmtp {
    
    public static void main(String[] args){
        Properties props = System.getProperties();
        props.setProperty("mail.debug","true");
        props.setProperty("mail.smtp.host", "localhost");
        props.setProperty("mail.smtp.user","a");
        
        // 2. session 가져오기
        Session session = Session.getInstance(props);
        Message msg = new MimeMessage(session);
       

        try {
            
            Address[] toAddrs = {new InternetAddress("test1@localhost")};
            Address fromAddr = new InternetAddress("a@localhost");

            msg.setFrom(fromAddr);  
            msg.setRecipients(Message.RecipientType.TO, toAddrs);
            msg.setSubject(MimeUtility.encodeText("메일 송신 프로그램 예제","UTF-8","B"));
            
            msg.setSentDate(new Date());
            
            String content = "this is content for test mail";
            msg.setContent(content,"text/plain");
            
            Transport trans = session.getTransport("smtp");
            trans.connect();
            trans.sendMessage(msg, toAddrs);
            trans.close();
            
          
        } catch (Exception ex) {
            System.out.println("sendMessage() error: " + ex);
        } 
    }  // sendMessage()
}
