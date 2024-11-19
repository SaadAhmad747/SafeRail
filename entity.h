#ifndef ENTITY_H
#define ENTITY_H
#define UPDATE_DRAW_MS      (5)

#define GET_CUR_TIME_MILLI (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count())


struct RadarCluster{
    float rangeM;
    float angleDeg;
    float velocity;
};


#endif // ENTITY_H
