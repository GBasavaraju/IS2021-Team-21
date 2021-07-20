using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;
using System;
using System.Threading;

public class UnityToArduino : MonoBehaviour
{
    public SerialPort serial = new SerialPort("COM3",9600);

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (serial.IsOpen==false)
            serial.Open();
        if (Input.GetKeyDown(KeyCode.A) )
        {
            Debug.Log("A");
            serial.Write("A");
        }
        else 
        {
            serial.Write("B");
        }
    }
}
