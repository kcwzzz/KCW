using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CBullet : MonoBehaviour
{
    private float mBulletDIrX = 0.0f;

    // Use this for initialization
    void Start()
    {

    }

    public void  SetBuletDirX(float tDirX)
    {
        mBulletDIrX = tDirX;
    }

    // Update is called once per frame
    void Update()
    {        
        this.transform.Translate(new Vector3(mBulletDIrX * Time.deltaTime, 0.0f, 0.0f));

        if (this.transform.position.x > 3.0f || this.transform.position.x < -3.0f)
        {
            Destroy(this.gameObject, 5.0f);
        }
    }


    void OnTriggerEnter2D(Collider2D tColider)
    {
        if (true == tColider.CompareTag("tagEnemy"))
        {
            Destroy(this.gameObject);
            Destroy(tColider.gameObject);
        }
    }
}
