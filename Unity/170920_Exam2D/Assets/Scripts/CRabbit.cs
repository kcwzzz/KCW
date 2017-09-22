using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CRabbit : CEnemy
{

    int ti = 0;
    float tDirX = 1.0f;

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        ti++;
        /*        this.transform.position = Vector3.MoveTowards(this.transform.position,
            Vector3.zero, 1.0f * Time.deltaTime);
            */

        if(this.transform.position.x >10.0f)
        {
            tDirX = -1.0f;
            this.transform.localScale = new Vector3(-1, 1, 1);

        }
        else if(this.transform.position.x < -10.0f)
        {
            tDirX = 1.0f;
            this.transform.localScale = new Vector3(1, 1, 1);
        }

        this.transform.Translate(new Vector3(0.07f*tDirX, 0.1f*Mathf.Sin(ti*0.1f), 0.0f));

    }
}
