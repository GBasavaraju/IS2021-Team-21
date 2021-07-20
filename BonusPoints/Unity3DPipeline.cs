using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Threading;


public class Ball : MonoBehaviour
{
    public string pattern="";
    public int collision = 1 ;
    public int sec= 0;
    public int decimal_value;
    public int first_digit;
    public int second_digit;
    Vector3 originalPos;
    // Start is called before the first frame update
    void Start()
    {
        
        originalPos = new Vector3(gameObject.transform.position.x, gameObject.transform.position.y, gameObject.transform.position.z);
    }

    // Update is called once per frame
    void Update()
    {

        if (Input.GetKeyDown(KeyCode.Alpha1) )
        {
            pattern+="1";
        }
        if (Input.GetKeyDown(KeyCode.Alpha2) )
        {
            pattern+= "2";
        }
        if (Input.GetKeyDown(KeyCode.Alpha3) )
        {
            pattern+= "3";
        }
        if (Input.GetKeyDown(KeyCode.Alpha4) )
        {
            pattern+= "4";
        }
        if (Input.GetKeyDown(KeyCode.Alpha5) )
        {
            pattern+= "5";
        }
        if (Input.GetKeyDown(KeyCode.Alpha6) )
        {
            pattern+= "6";
        }
        if (Input.GetKeyDown(KeyCode.Alpha7) )
        {
            pattern+= "7";
        }
        if (Input.GetKeyDown(KeyCode.Alpha8) )
        {
            pattern+= "8";
        }
        if (Input.GetKeyDown(KeyCode.Alpha9) )
        {
            pattern+= "9";
        }
        if (Input.GetKeyDown(KeyCode.Alpha0) )
        {
            pattern+= "0";
        }
        if (Input.GetKeyDown(KeyCode.A) )
        {
            pattern+= "a";
        }
        if (Input.GetKeyDown(KeyCode.B) )
        {
            pattern+= "b";
        }
        if (Input.GetKeyDown(KeyCode.C) )
        {
            pattern+= "c";
        }
        if (Input.GetKeyDown(KeyCode.D) )
        {
            pattern+= "d";
        }
        if (Input.GetKeyDown(KeyCode.E) )
        {
            pattern+= "e";
        }
        if (Input.GetKeyDown(KeyCode.F) )
        {
            pattern+= "f";
        }  
        if (Input.GetKeyDown(KeyCode.H) )
        {
            pattern+= "h";
        }      
        
        if (pattern.EndsWith("h")){
        pattern = pattern.Substring(0, pattern.Length-1);
        decimal_value = Convert.ToInt32(pattern, 16);
        if(decimal_value>9){
        first_digit = decimal_value / 10;
        second_digit = decimal_value % 10;
        }
        else
        {
        first_digit = decimal_value;
        second_digit=555;
        }
        Debug.Log("Input - Hex value ="+pattern);
        Debug.Log("Output - Decimal value ="+decimal_value);
        }
    }

    private void FixedUpdate()
    {

        if(first_digit==1)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,6,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,10);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==2)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,6);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==3)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,5);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==4)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-5);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==5)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-6);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==6)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,6,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-10);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==7)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(6,GetComponent<Rigidbody>().velocity.y,0);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==8)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(5,GetComponent<Rigidbody>().velocity.y,0);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }
        if(first_digit==9)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);  
            GetComponent<Rigidbody>().velocity= new Vector3(-5,GetComponent<Rigidbody>().velocity.y,0);
            sec=second_digit;
            collision=2;
            first_digit=555;  
            pattern="";                    
        }

  
    }

    void OnTriggerEnter(Collider other)
    {   
             
       if(other.gameObject.tag == "End")
        {
            Thread.Sleep(2000);
            gameObject.transform.position = originalPos;
            GetComponent<Rigidbody>().velocity= new Vector3(0,0,0);
            collision = collision+1;
        }
     
        if(other.gameObject.tag == "Base"){
        if(collision==3 ){ 
         Thread.Sleep(2000);
            if(sec==1) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,10);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,6,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==2) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,6);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==3) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,5);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==4) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-6);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==5) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-6);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==6) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(0,GetComponent<Rigidbody>().velocity.y,-10);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,6,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==7) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(6,GetComponent<Rigidbody>().velocity.y,0);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==8) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(5,GetComponent<Rigidbody>().velocity.y,0);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);
                sec=555;
            }
            if(sec==9) 
            {
                GetComponent<Rigidbody>().AddForce(new Vector3(0,4,0), ForceMode.VelocityChange);
                GetComponent<Rigidbody>().velocity= new Vector3(-5,GetComponent<Rigidbody>().velocity.y,0);
                sec=555;
            }
            if(sec==0) 
            {
                GetComponent<Rigidbody>().velocity= new Vector3(-6,GetComponent<Rigidbody>().velocity.y,0);
                GetComponent<Rigidbody>().AddForce(new Vector3(0,7,0), ForceMode.VelocityChange);
                sec=555;
            }
                
            }
        }
    }
}
