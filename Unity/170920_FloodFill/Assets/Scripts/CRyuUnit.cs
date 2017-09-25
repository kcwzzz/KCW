using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CRyuUnit : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    virtual public void DoMove()
    {
        this.transform.Translate(Vector3.forward, Space.Self);
        //forward z축의  +방향으로, 1Unit씩 Self = 로컬 좌표계(알베르토의 좌표) 

    }

    virtual public void DoRatote()
    {
        this.transform.Rotate(Vector3.up, 90.0f, Space.Self);
    }


}
