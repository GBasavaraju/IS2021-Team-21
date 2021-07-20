using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;

public class arduinoUnity : MonoBehaviour
{
    public float speed;
    private float amoutToMove;
    SerialPort sp = new SerialPort("COM3", 9600);
    // Start is called before the first frame update
    void Start()
    {
        sp.Open();
        sp.ReadTimeout =1;
    }

    // Update is called once per frame
    void Update()
    {
        amoutToMove = speed * Time.deltaTime;
        if (sp.IsOpen)
        {
            try
            {
                MoveObject(sp.ReadByte());
               // print(sp.ReadByte());
            }
            catch (System.Exception)
            {

            }
        }
    }

    void MoveObject(int Direction)
    {
        gameObject.GetComponent<Renderer>().enabled = true;
        if (Direction ==1)
        {
            gameObject.GetComponent<Renderer>().enabled = false;
            Debug.Log("Arduino here");
            Direction =0;
        }
        if (Direction ==2)
        {
            GetComponent<Rigidbody>().AddForce(new Vector3(0,0,0), ForceMode.VelocityChange);
            Debug.Log("Right");        
        }
    }
}
