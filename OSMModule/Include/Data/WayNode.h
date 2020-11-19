#ifndef WAYNODE_H
#define WAYNODE_H

#include "LatLon.h"

struct WayNode
{
    LatLon coord;

    wstring access;
    wstring amenity;
    wstring barrier;
    wstring bench;
    wstring bicycle;
    wstring bin;
    wstring bollard;
    wstring bus;
    wstring capacity_parent;
    wstring communication_gsm_r;
    wstring communication_mobile_phone;
    wstring covered;
    wstring crossing;
    wstring crossing_activation;
    wstring crossing_barrier;
    wstring crossing_chicane;
    wstring crossing_island;
    wstring crossing_light;
    wstring crossing_saltire;
    wstring description;
    wstring direction;
    wstring direction_east;
    wstring direction_south;
    wstring emergency;
    wstring emergency_telephone_code;
    wstring fee;
    wstring foot;
    wstring highway;
    wstring hiking;
    wstring horse;
    wstring information;
    wstring kerb;
    wstring lcn;
    wstring man_made;
    wstring material;
    wstring name;
    wstring network;
    wstring noexit;
    wstring noref;
    wstring note;
    wstring official_name;
    wstring old_name;
    wstring operator_;
    wstring parking;
    wstring public_transport;
    wstring railway;
    wstring railway_derail;
    wstring railway_local_operated;
    wstring railway_milestone_catenary_mast;
    wstring railway_milestone_emergency_brake_override;
    wstring railway_position;
    wstring railway_position_exact;
    wstring railway_radio;
    wstring railway_ref;
    wstring railway_signal_catenary_mast;
    wstring railway_signal_crossing_form;
    wstring railway_signal_crossing_distant_form;
    wstring railway_signal_direction;
    wstring railway_signal_distant;
    wstring railway_signal_distant_form;
    wstring railway_signal_distant_height;
    wstring railway_signal_distant_repeated;
    wstring railway_signal_distant_shortened;
    wstring railway_signal_distant_states;
    wstring railway_signal_electricity;
    wstring railway_signal_electricity_form;
    wstring railway_signal_electricity_height;
    wstring railway_signal_electricity_turn_direction;
    wstring railway_signal_electricity_type;
    wstring railway_signal_expected_position_height;
    wstring railway_signal_main;
    wstring railway_signal_main_deactivated;
    wstring railway_signal_main_form;
    wstring railway_signal_main_function;
    wstring railway_signal_main_height;
    wstring railway_signal_main_states;
    wstring railway_signal_main_substitute_signal;
    wstring railway_signal_main_repeated;
    wstring railway_signal_main_repeated_form;
    wstring railway_signal_minor;
    wstring railway_signal_minor_form;
    wstring railway_signal_minor_height;
    wstring railway_signal_minor_states;
    wstring railway_signal_position;
    wstring railway_signal_shunting;
    wstring railway_signal_shunting_form;
    wstring railway_signal_shunting_height;
    wstring railway_signal_speed_limit;
    wstring railway_signal_speed_limit_form;
    wstring railway_signal_speed_limit_height;
    wstring railway_signal_speed_limit_speed;
    wstring railway_signal_speed_limit_distant;
    wstring railway_signal_speed_limit_distant_form;
    wstring railway_signal_speed_limit_distant_height;
    wstring railway_signal_speed_limit_distant_speed;
    wstring railway_signal_station_distant;
    wstring railway_signal_station_distant_form;
    wstring railway_signal_traversable_type;
    wstring railway_signal_whistle;
    wstring railway_signal_whistle_form;
    wstring railway_signal_wrong_road;
    wstring railway_signal_wrong_road_form;
    wstring railway_station_category;
    wstring railway_switch;
    wstring railway_switch_configuration;
    wstring railway_switch_electric;
    wstring railway_switch_movable_frog;
    wstring railway_switch_resetting;
    wstring railway_turnout_side;
    wstring razed;
    wstring ref;
    wstring ref_IFOPT;
    wstring ref_station;
    wstring route_ref;
    wstring shelter;
    wstring source_date;
    wstring supervised;
    wstring tactile_paving;
    wstring tourism;
    wstring tower_type;
    wstring traffic_calming;
    wstring traffic_sign;
    wstring train;
    wstring uic_name;
    wstring uic_ref;
    wstring wheelchair;
    wstring wheelchair_description;

public:
    inline void ParseFromOSMJson(JSONValue* json)
    {
        this->coord = LatLon(json);

        JSONObject obj = json->AsObject();
        JSONObject tags = obj[L"tags"]->AsObject();

        if (tags[L"access"] != NULL)
            this->access = tags[L"access"]->AsString();

        if (tags[L"amenity"] != NULL)
            this->amenity = tags[L"amenity"]->AsString();

        if (tags[L"barrier"] != NULL)
            this->barrier = tags[L"barrier"]->AsString();

        if (tags[L"bench"] != NULL)
            this->bench = tags[L"bench"]->AsString();

        if (tags[L"bicycle"] != NULL)
            this->bicycle = tags[L"bicycle"]->AsString();

        if (tags[L"bin"] != NULL)
            this->bin = tags[L"bin"]->AsString();

        if (tags[L"bollard"] != NULL)
            this->bollard = tags[L"bollard"]->AsString();

        if (tags[L"bus"] != NULL)
            this->bus = tags[L"bus"]->AsString();

        if (tags[L"capacity:parent"] != NULL)
            this->capacity_parent = tags[L"capacity:parent"]->AsString();

        if (tags[L"communication:gsm-r"] != NULL)
            this->communication_gsm_r = tags[L"communication:gsm-r"]->AsString();

        if (tags[L"communication:mobile_phone"] != NULL)
            this->communication_mobile_phone = tags[L"communication:mobile_phone"]->AsString();

        if (tags[L"covered"] != NULL)
            this->covered = tags[L"covered"]->AsString();

        if (tags[L"crossing"] != NULL)
            this->crossing = tags[L"crossing"]->AsString();

        if (tags[L"crossing:activation"] != NULL)
            this->crossing_activation = tags[L"crossing:activation"]->AsString();

        if (tags[L"crossing:barrier"] != NULL)
            this->crossing_barrier = tags[L"crossing:barrier"]->AsString();

        if (tags[L"crossing:chicane"] != NULL)
            this->crossing_chicane = tags[L"crossing:chicane"]->AsString();

        if (tags[L"crossing:island"] != NULL)
            this->crossing_island = tags[L"crossing:island"]->AsString();

        if (tags[L"crossing:light"] != NULL)
            this->crossing_light = tags[L"crossing:light"]->AsString();

        if (tags[L"crossing:saltire"] != NULL)
            this->crossing_saltire = tags[L"crossing:saltire"]->AsString();

        if (tags[L"description"] != NULL)
            this->description = tags[L"description"]->AsString();

        if (tags[L"direction"] != NULL)
            this->direction = tags[L"direction"]->AsString();

        if (tags[L"direction_east"] != NULL)
            this->direction_east = tags[L"direction_east"]->AsString();

        if (tags[L"direction_south"] != NULL)
            this->direction_south = tags[L"direction_south"]->AsString();

        if (tags[L"emergency"] != NULL)
            this->emergency = tags[L"emergency"]->AsString();

        if (tags[L"emergency_telephone_code"] != NULL)
            this->emergency_telephone_code = tags[L"emergency_telephone_code"]->AsString();

        if (tags[L"fee"] != NULL)
            this->fee = tags[L"fee"]->AsString();

        if (tags[L"foot"] != NULL)
            this->foot = tags[L"foot"]->AsString();

        if (tags[L"highway"] != NULL)
            this->highway = tags[L"highway"]->AsString();

        if (tags[L"hiking"] != NULL)
            this->hiking = tags[L"hiking"]->AsString();

        if (tags[L"horse"] != NULL)
            this->horse = tags[L"horse"]->AsString();

        if (tags[L"information"] != NULL)
            this->information = tags[L"information"]->AsString();

        if (tags[L"kerb"] != NULL)
            this->kerb = tags[L"kerb"]->AsString();

        if (tags[L"lcn"] != NULL)
            this->lcn = tags[L"lcn"]->AsString();

        if (tags[L"man_made"] != NULL)
            this->man_made = tags[L"man_made"]->AsString();

        if (tags[L"material"] != NULL)
            this->material = tags[L"material"]->AsString();

        if (tags[L"name"] != NULL)
            this->name = tags[L"name"]->AsString();

        if (tags[L"network"] != NULL)
            this->network = tags[L"network"]->AsString();

        if (tags[L"noexit"] != NULL)
            this->noexit = tags[L"noexit"]->AsString();

        if (tags[L"noref"] != NULL)
            this->noref = tags[L"noref"]->AsString();

        if (tags[L"note"] != NULL)
            this->note = tags[L"note"]->AsString();

        if (tags[L"official_name"] != NULL)
            this->official_name = tags[L"official_name"]->AsString();

        if (tags[L"old_name"] != NULL)
            this->old_name = tags[L"old_name"]->AsString();

        if (tags[L"operator"] != NULL)
            this->operator_ = tags[L"operator"]->AsString();

        if (tags[L"parking"] != NULL)
            this->parking = tags[L"parking"]->AsString();

        if (tags[L"public_transport"] != NULL)
            this->public_transport = tags[L"public_transport"]->AsString();

        if (tags[L"railway"] != NULL)
            this->railway = tags[L"railway"]->AsString();

        if (tags[L"railway:derail"] != NULL)
            this->railway_derail = tags[L"railway:derail"]->AsString();

        if (tags[L"railway:local_operated"] != NULL)
            this->railway_local_operated = tags[L"railway:local_operated"]->AsString();

        if (tags[L"railway:milestone:catenary_mast"] != NULL)
            this->railway_milestone_catenary_mast = tags[L"railway:milestone:catenary_mast"]->AsString();

        if (tags[L"railway:milestone:emergency_brake_override"] != NULL)
            this->railway_milestone_emergency_brake_override = tags[L"railway:milestone:emergency_brake_override"]->AsString();

        if (tags[L"railway:position"] != NULL)
            this->railway_position = tags[L"railway:position"]->AsString();

        if (tags[L"railway:position:exact"] != NULL)
            this->railway_position_exact = tags[L"railway:position:exact"]->AsString();

        if (tags[L"railway:radio"] != NULL)
            this->railway_radio = tags[L"railway:radio"]->AsString();

        if (tags[L"railway:ref"] != NULL)
            this->railway_ref = tags[L"railway:ref"]->AsString();

        if (tags[L"railway:signal:catenary_mast"] != NULL)
            this->railway_signal_catenary_mast = tags[L"railway:signal:catenary_mast"]->AsString();

        if (tags[L"railway:signal:crossing:form"] != NULL)
            this->railway_signal_crossing_form = tags[L"railway:signal:crossing:form"]->AsString();

        if (tags[L"railway:signal:crossing_distant:form"] != NULL)
            this->railway_signal_crossing_distant_form = tags[L"railway:signal:crossing_distant:form"]->AsString();

        if (tags[L"railway:signal:direction"] != NULL)
            this->railway_signal_direction = tags[L"railway:signal:direction"]->AsString();

        if (tags[L"railway:signal:distant"] != NULL)
            this->railway_signal_distant = tags[L"railway:signal:distant"]->AsString();

        if (tags[L"railway:signal:distant:form"] != NULL)
            this->railway_signal_distant_form = tags[L"railway:signal:distant:form"]->AsString();

        if (tags[L"railway:signal:distant:height"] != NULL)
            this->railway_signal_distant_height = tags[L"railway:signal:distant:height"]->AsString();

        if (tags[L"railway:signal:distant:repeated"] != NULL)
            this->railway_signal_distant_repeated = tags[L"railway:signal:distant:repeated"]->AsString();

        if (tags[L"railway:signal:distant:shortened"] != NULL)
            this->railway_signal_distant_shortened = tags[L"railway:signal:distant:shortened"]->AsString();

        if (tags[L"railway:signal:distant:states"] != NULL)
            this->railway_signal_distant_states = tags[L"railway:signal:distant:states"]->AsString();

        if (tags[L"railway:signal:electricity"] != NULL)
            this->railway_signal_electricity = tags[L"railway:signal:electricity"]->AsString();

        if (tags[L"railway:signal:electricity:form"] != NULL)
            this->railway_signal_electricity_form = tags[L"railway:signal:electricity:form"]->AsString();

        if (tags[L"railway:signal:electricity:height"] != NULL)
            this->railway_signal_electricity_height = tags[L"railway:signal:electricity:height"]->AsString();

        if (tags[L"railway:signal:electricity:turn_direction"] != NULL)
            this->railway_signal_electricity_turn_direction = tags[L"railway:signal:electricity:turn_direction"]->AsString();

        if (tags[L"railway:signal:electricity:type"] != NULL)
            this->railway_signal_electricity_type = tags[L"railway:signal:electricity:type"]->AsString();

        if (tags[L"railway:signal:expected_position:height"] != NULL)
            this->railway_signal_expected_position_height = tags[L"railway:signal:expected_position:height"]->AsString();

        if (tags[L"railway:signal:main"] != NULL)
            this->railway_signal_main = tags[L"railway:signal:main"]->AsString();

        if (tags[L"railway:signal:main:deactivated"] != NULL)
            this->railway_signal_main_deactivated = tags[L"railway:signal:main:deactivated"]->AsString();

        if (tags[L"railway:signal:main:form"] != NULL)
            this->railway_signal_main_form = tags[L"railway:signal:main:form"]->AsString();

        if (tags[L"railway:signal:main:function"] != NULL)
            this->railway_signal_main_function = tags[L"railway:signal:main:function"]->AsString();

        if (tags[L"railway:signal:main:height"] != NULL)
            this->railway_signal_main_height = tags[L"railway:signal:main:height"]->AsString();

        if (tags[L"railway:signal:main:states"] != NULL)
            this->railway_signal_main_states = tags[L"railway:signal:main:states"]->AsString();

        if (tags[L"railway:signal:main:substitute_signal"] != NULL)
            this->railway_signal_main_substitute_signal = tags[L"railway:signal:main:substitute_signal"]->AsString();

        if (tags[L"railway:signal:main_repeated"] != NULL)
            this->railway_signal_main_repeated = tags[L"railway:signal:main_repeated"]->AsString();

        if (tags[L"railway:signal:main_repeated:form"] != NULL)
            this->railway_signal_main_repeated_form = tags[L"railway:signal:main_repeated:form"]->AsString();

        if (tags[L"railway:signal:minor"] != NULL)
            this->railway_signal_minor = tags[L"railway:signal:minor"]->AsString();

        if (tags[L"railway:signal:minor:form"] != NULL)
            this->railway_signal_minor_form = tags[L"railway:signal:minor:form"]->AsString();

        if (tags[L"railway:signal:minor:height"] != NULL)
            this->railway_signal_minor_height = tags[L"railway:signal:minor:height"]->AsString();

        if (tags[L"railway:signal:minor:states"] != NULL)
            this->railway_signal_minor_states = tags[L"railway:signal:minor:states"]->AsString();

        if (tags[L"railway:signal:position"] != NULL)
            this->railway_signal_position = tags[L"railway:signal:position"]->AsString();

        if (tags[L"railway:signal:shunting"] != NULL)
            this->railway_signal_shunting = tags[L"railway:signal:shunting"]->AsString();

        if (tags[L"railway:signal:shunting:form"] != NULL)
            this->railway_signal_shunting_form = tags[L"railway:signal:shunting:form"]->AsString();

        if (tags[L"railway:signal:shunting:height"] != NULL)
            this->railway_signal_shunting_height = tags[L"railway:signal:shunting:height"]->AsString();

        if (tags[L"railway:signal:speed_limit"] != NULL)
            this->railway_signal_speed_limit = tags[L"railway:signal:speed_limit"]->AsString();

        if (tags[L"railway:signal:speed_limit:form"] != NULL)
            this->railway_signal_speed_limit_form = tags[L"railway:signal:speed_limit:form"]->AsString();

        if (tags[L"railway:signal:speed_limit:height"] != NULL)
            this->railway_signal_speed_limit_height = tags[L"railway:signal:speed_limit:height"]->AsString();

        if (tags[L"railway:signal:speed_limit:speed"] != NULL)
            this->railway_signal_speed_limit_speed = tags[L"railway:signal:speed_limit:speed"]->AsString();

        if (tags[L"railway:signal:speed_limit_distant"] != NULL)
            this->railway_signal_speed_limit_distant = tags[L"railway:signal:speed_limit_distant"]->AsString();

        if (tags[L"railway:signal:speed_limit_distant:form"] != NULL)
            this->railway_signal_speed_limit_distant_form = tags[L"railway:signal:speed_limit_distant:form"]->AsString();

        if (tags[L"railway:signal:speed_limit_distant:height"] != NULL)
            this->railway_signal_speed_limit_distant_height = tags[L"railway:signal:speed_limit_distant:height"]->AsString();

        if (tags[L"railway:signal:speed_limit_distant:speed"] != NULL)
            this->railway_signal_speed_limit_distant_speed = tags[L"railway:signal:speed_limit_distant:speed"]->AsString();

        if (tags[L"railway:signal:station_distant"] != NULL)
            this->railway_signal_station_distant = tags[L"railway:signal:station_distant"]->AsString();

        if (tags[L"railway:signal:station_distant:form"] != NULL)
            this->railway_signal_station_distant_form = tags[L"railway:signal:station_distant:form"]->AsString();

        if (tags[L"railway:signal:traversable:type"] != NULL)
            this->railway_signal_traversable_type = tags[L"railway:signal:traversable:type"]->AsString();

        if (tags[L"railway:signal:whistle"] != NULL)
            this->railway_signal_whistle = tags[L"railway:signal:whistle"]->AsString();

        if (tags[L"railway:signal:whistle:form"] != NULL)
            this->railway_signal_whistle_form = tags[L"railway:signal:whistle:form"]->AsString();

        if (tags[L"railway:signal:wrong_road"] != NULL)
            this->railway_signal_wrong_road = tags[L"railway:signal:wrong_road"]->AsString();

        if (tags[L"railway:signal:wrong_road:form"] != NULL)
            this->railway_signal_wrong_road_form = tags[L"railway:signal:wrong_road:form"]->AsString();

        if (tags[L"railway:station_category"] != NULL)
            this->railway_station_category = tags[L"railway:station_category"]->AsString();

        if (tags[L"railway:switch"] != NULL)
            this->railway_switch = tags[L"railway:switch"]->AsString();

        if (tags[L"railway:switch:configuration"] != NULL)
            this->railway_switch_configuration = tags[L"railway:switch:configuration"]->AsString();

        if (tags[L"railway:switch:electric"] != NULL)
            this->railway_switch_electric = tags[L"railway:switch:electric"]->AsString();

        if (tags[L"railway:switch:movable_frog"] != NULL)
            this->railway_switch_movable_frog = tags[L"railway:switch:movable_frog"]->AsString();

        if (tags[L"railway:switch:resetting"] != NULL)
            this->railway_switch_resetting = tags[L"railway:switch:resetting"]->AsString();

        if (tags[L"railway:turnout_side"] != NULL)
            this->railway_turnout_side = tags[L"railway:turnout_side"]->AsString();

        if (tags[L"razed"] != NULL)
            this->razed = tags[L"razed"]->AsString();

        if (tags[L"ref"] != NULL)
            this->ref = tags[L"ref"]->AsString();

        if (tags[L"ref:IFOPT"] != NULL)
            this->ref_IFOPT = tags[L"ref:IFOPT"]->AsString();

        if (tags[L"ref:station"] != NULL)
            this->ref_station = tags[L"ref:station"]->AsString();

        if (tags[L"route_ref"] != NULL)
            this->route_ref = tags[L"route_ref"]->AsString();

        if (tags[L"shelter"] != NULL)
            this->shelter = tags[L"shelter"]->AsString();

        if (tags[L"source:date"] != NULL)
            this->source_date = tags[L"source:date"]->AsString();

        if (tags[L"supervised"] != NULL)
            this->supervised = tags[L"supervised"]->AsString();

        if (tags[L"tactile_paving"] != NULL)
            this->tactile_paving = tags[L"tactile_paving"]->AsString();

        if (tags[L"tourism"] != NULL)
            this->tourism = tags[L"tourism"]->AsString();

        if (tags[L"tower:type"] != NULL)
            this->tower_type = tags[L"tower:type"]->AsString();

        if (tags[L"traffic_calming"] != NULL)
            this->traffic_calming = tags[L"traffic_calming"]->AsString();

        if (tags[L"traffic_sign"] != NULL)
            this->traffic_sign = tags[L"traffic_sign"]->AsString();

        if (tags[L"train"] != NULL)
            this->train = tags[L"train"]->AsString();

        if (tags[L"uic_name"] != NULL)
            this->uic_name = tags[L"uic_name"]->AsString();

        if (tags[L"uic_ref"] != NULL)
            this->uic_ref = tags[L"uic_ref"]->AsString();

        if (tags[L"wheelchair"] != NULL)
            this->wheelchair = tags[L"wheelchair"]->AsString();

        if (tags[L"wheelchair:description"] != NULL)
            this->wheelchair_description = tags[L"wheelchair:description"]->AsString();
    }

    inline JSONValue* ToJSONObject() // NOTE: pointer must be released later
    {
        JSONObject obj;

        obj[L"coord"] = coord.ToJSONObject();

        if (!this->access.empty())
            obj[L"access"] = new JSONValue(this->access);

        if (!this->amenity.empty())
            obj[L"amenity"] = new JSONValue(this->amenity);

        if (!this->barrier.empty())
            obj[L"barrier"] = new JSONValue(this->barrier);

        if (!this->bench.empty())
            obj[L"bench"] = new JSONValue(this->bench);

        if (!this->bicycle.empty())
            obj[L"bicycle"] = new JSONValue(this->bicycle);

        if (!this->bin.empty())
            obj[L"bin"] = new JSONValue(this->bin);

        if (!this->bollard.empty())
            obj[L"bollard"] = new JSONValue(this->bollard);

        if (!this->bus.empty())
            obj[L"bus"] = new JSONValue(this->bus);

        if (!this->capacity_parent.empty())
            obj[L"capacity:parent"] = new JSONValue(this->capacity_parent);

        if (!this->communication_gsm_r.empty())
            obj[L"communication:gsm-r"] = new JSONValue(this->communication_gsm_r);

        if (!this->communication_mobile_phone.empty())
            obj[L"communication:mobile_phone"] = new JSONValue(this->communication_mobile_phone);

        if (!this->covered.empty())
            obj[L"covered"] = new JSONValue(this->covered);

        if (!this->crossing.empty())
            obj[L"crossing"] = new JSONValue(this->crossing);

        if (!this->crossing_activation.empty())
            obj[L"crossing:activation"] = new JSONValue(this->crossing_activation);

        if (!this->crossing_barrier.empty())
            obj[L"crossing:barrier"] = new JSONValue(this->crossing_barrier);

        if (!this->crossing_chicane.empty())
            obj[L"crossing:chicane"] = new JSONValue(this->crossing_chicane);

        if (!this->crossing_island.empty())
            obj[L"crossing:island"] = new JSONValue(this->crossing_island);

        if (!this->crossing_light.empty())
            obj[L"crossing:light"] = new JSONValue(this->crossing_light);

        if (!this->crossing_saltire.empty())
            obj[L"crossing:saltire"] = new JSONValue(this->crossing_saltire);

        if (!this->description.empty())
            obj[L"description"] = new JSONValue(this->description);

        if (!this->direction.empty())
            obj[L"direction"] = new JSONValue(this->direction);

        if (!this->direction_east.empty())
            obj[L"direction_east"] = new JSONValue(this->direction_east);

        if (!this->direction_south.empty())
            obj[L"direction_south"] = new JSONValue(this->direction_south);

        if (!this->emergency.empty())
            obj[L"emergency"] = new JSONValue(this->emergency);

        if (!this->emergency_telephone_code.empty())
            obj[L"emergency_telephone_code"] = new JSONValue(this->emergency_telephone_code);

        if (!this->fee.empty())
            obj[L"fee"] = new JSONValue(this->fee);

        if (!this->foot.empty())
            obj[L"foot"] = new JSONValue(this->foot);

        if (!this->highway.empty())
            obj[L"highway"] = new JSONValue(this->highway);

        if (!this->hiking.empty())
            obj[L"hiking"] = new JSONValue(this->hiking);

        if (!this->horse.empty())
            obj[L"horse"] = new JSONValue(this->horse);

        if (!this->information.empty())
            obj[L"information"] = new JSONValue(this->information);

        if (!this->kerb.empty())
            obj[L"kerb"] = new JSONValue(this->kerb);

        if (!this->lcn.empty())
            obj[L"lcn"] = new JSONValue(this->lcn);

        if (!this->man_made.empty())
            obj[L"man_made"] = new JSONValue(this->man_made);

        if (!this->material.empty())
            obj[L"material"] = new JSONValue(this->material);

        if (!this->name.empty())
            obj[L"name"] = new JSONValue(this->name);

        if (!this->network.empty())
            obj[L"network"] = new JSONValue(this->network);

        if (!this->noexit.empty())
            obj[L"noexit"] = new JSONValue(this->noexit);

        if (!this->noref.empty())
            obj[L"noref"] = new JSONValue(this->noref);

        if (!this->note.empty())
            obj[L"note"] = new JSONValue(this->note);

        if (!this->official_name.empty())
            obj[L"official_name"] = new JSONValue(this->official_name);

        if (!this->old_name.empty())
            obj[L"old_name"] = new JSONValue(this->old_name);

        if (!this->operator_.empty())
            obj[L"operator"] = new JSONValue(this->operator_);

        if (!this->parking.empty())
            obj[L"parking"] = new JSONValue(this->parking);

        if (!this->public_transport.empty())
            obj[L"public_transport"] = new JSONValue(this->public_transport);

        if (!this->railway.empty())
            obj[L"railway"] = new JSONValue(this->railway);

        if (!this->railway_derail.empty())
            obj[L"railway:derail"] = new JSONValue(this->railway_derail);

        if (!this->railway_local_operated.empty())
            obj[L"railway:local_operated"] = new JSONValue(this->railway_local_operated);

        if (!this->railway_milestone_catenary_mast.empty())
            obj[L"railway:milestone:catenary_mast"] = new JSONValue(this->railway_milestone_catenary_mast);

        if (!this->railway_milestone_emergency_brake_override.empty())
            obj[L"railway:milestone:emergency_brake_override"] = new JSONValue(this->railway_milestone_emergency_brake_override);

        if (!this->railway_position.empty())
            obj[L"railway:position"] = new JSONValue(this->railway_position);

        if (!this->railway_position_exact.empty())
            obj[L"railway:position:exact"] = new JSONValue(this->railway_position_exact);

        if (!this->railway_radio.empty())
            obj[L"railway:radio"] = new JSONValue(this->railway_radio);

        if (!this->railway_ref.empty())
            obj[L"railway:ref"] = new JSONValue(this->railway_ref);

        if (!this->railway_signal_catenary_mast.empty())
            obj[L"railway:signal:catenary_mast"] = new JSONValue(this->railway_signal_catenary_mast);

        if (!this->railway_signal_crossing_form.empty())
            obj[L"railway:signal:crossing:form"] = new JSONValue(this->railway_signal_crossing_form);

        if (!this->railway_signal_crossing_distant_form.empty())
            obj[L"railway:signal:crossing_distant:form"] = new JSONValue(this->railway_signal_crossing_distant_form);

        if (!this->railway_signal_direction.empty())
            obj[L"railway:signal:direction"] = new JSONValue(this->railway_signal_direction);

        if (!this->railway_signal_distant.empty())
            obj[L"railway:signal:distant"] = new JSONValue(this->railway_signal_distant);

        if (!this->railway_signal_distant_form.empty())
            obj[L"railway:signal:distant:form"] = new JSONValue(this->railway_signal_distant_form);

        if (!this->railway_signal_distant_height.empty())
            obj[L"railway:signal:distant:height"] = new JSONValue(this->railway_signal_distant_height);

        if (!this->railway_signal_distant_repeated.empty())
            obj[L"railway:signal:distant:repeated"] = new JSONValue(this->railway_signal_distant_repeated);

        if (!this->railway_signal_distant_shortened.empty())
            obj[L"railway:signal:distant:shortened"] = new JSONValue(this->railway_signal_distant_shortened);

        if (!this->railway_signal_distant_states.empty())
            obj[L"railway:signal:distant:states"] = new JSONValue(this->railway_signal_distant_states);

        if (!this->railway_signal_electricity.empty())
            obj[L"railway:signal:electricity"] = new JSONValue(this->railway_signal_electricity);

        if (!this->railway_signal_electricity_form.empty())
            obj[L"railway:signal:electricity:form"] = new JSONValue(this->railway_signal_electricity_form);

        if (!this->railway_signal_electricity_height.empty())
            obj[L"railway:signal:electricity:height"] = new JSONValue(this->railway_signal_electricity_height);

        if (!this->railway_signal_electricity_turn_direction.empty())
            obj[L"railway:signal:electricity:turn_direction"] = new JSONValue(this->railway_signal_electricity_turn_direction);

        if (!this->railway_signal_electricity_type.empty())
            obj[L"railway:signal:electricity:type"] = new JSONValue(this->railway_signal_electricity_type);

        if (!this->railway_signal_expected_position_height.empty())
            obj[L"railway:signal:expected_position:height"] = new JSONValue(this->railway_signal_expected_position_height);

        if (!this->railway_signal_main.empty())
            obj[L"railway:signal:main"] = new JSONValue(this->railway_signal_main);

        if (!this->railway_signal_main_deactivated.empty())
            obj[L"railway:signal:main:deactivated"] = new JSONValue(this->railway_signal_main_deactivated);

        if (!this->railway_signal_main_form.empty())
            obj[L"railway:signal:main:form"] = new JSONValue(this->railway_signal_main_form);

        if (!this->railway_signal_main_function.empty())
            obj[L"railway:signal:main:function"] = new JSONValue(this->railway_signal_main_function);

        if (!this->railway_signal_main_height.empty())
            obj[L"railway:signal:main:height"] = new JSONValue(this->railway_signal_main_height);

        if (!this->railway_signal_main_states.empty())
            obj[L"railway:signal:main:states"] = new JSONValue(this->railway_signal_main_states);

        if (!this->railway_signal_main_substitute_signal.empty())
            obj[L"railway:signal:main:substitute_signal"] = new JSONValue(this->railway_signal_main_substitute_signal);

        if (!this->railway_signal_main_repeated.empty())
            obj[L"railway:signal:main_repeated"] = new JSONValue(this->railway_signal_main_repeated);

        if (!this->railway_signal_main_repeated_form.empty())
            obj[L"railway:signal:main_repeated:form"] = new JSONValue(this->railway_signal_main_repeated_form);

        if (!this->railway_signal_minor.empty())
            obj[L"railway:signal:minor"] = new JSONValue(this->railway_signal_minor);

        if (!this->railway_signal_minor_form.empty())
            obj[L"railway:signal:minor:form"] = new JSONValue(this->railway_signal_minor_form);

        if (!this->railway_signal_minor_height.empty())
            obj[L"railway:signal:minor:height"] = new JSONValue(this->railway_signal_minor_height);

        if (!this->railway_signal_minor_states.empty())
            obj[L"railway:signal:minor:states"] = new JSONValue(this->railway_signal_minor_states);

        if (!this->railway_signal_position.empty())
            obj[L"railway:signal:position"] = new JSONValue(this->railway_signal_position);

        if (!this->railway_signal_shunting.empty())
            obj[L"railway:signal:shunting"] = new JSONValue(this->railway_signal_shunting);

        if (!this->railway_signal_shunting_form.empty())
            obj[L"railway:signal:shunting:form"] = new JSONValue(this->railway_signal_shunting_form);

        if (!this->railway_signal_shunting_height.empty())
            obj[L"railway:signal:shunting:height"] = new JSONValue(this->railway_signal_shunting_height);

        if (!this->railway_signal_speed_limit.empty())
            obj[L"railway:signal:speed_limit"] = new JSONValue(this->railway_signal_speed_limit);

        if (!this->railway_signal_speed_limit_form.empty())
            obj[L"railway:signal:speed_limit:form"] = new JSONValue(this->railway_signal_speed_limit_form);

        if (!this->railway_signal_speed_limit_height.empty())
            obj[L"railway:signal:speed_limit:height"] = new JSONValue(this->railway_signal_speed_limit_height);

        if (!this->railway_signal_speed_limit_speed.empty())
            obj[L"railway:signal:speed_limit:speed"] = new JSONValue(this->railway_signal_speed_limit_speed);

        if (!this->railway_signal_speed_limit_distant.empty())
            obj[L"railway:signal:speed_limit_distant"] = new JSONValue(this->railway_signal_speed_limit_distant);

        if (!this->railway_signal_speed_limit_distant_form.empty())
            obj[L"railway:signal:speed_limit_distant:form"] = new JSONValue(this->railway_signal_speed_limit_distant_form);

        if (!this->railway_signal_speed_limit_distant_height.empty())
            obj[L"railway:signal:speed_limit_distant:height"] = new JSONValue(this->railway_signal_speed_limit_distant_height);

        if (!this->railway_signal_speed_limit_distant_speed.empty())
            obj[L"railway:signal:speed_limit_distant:speed"] = new JSONValue(this->railway_signal_speed_limit_distant_speed);

        if (!this->railway_signal_station_distant.empty())
            obj[L"railway:signal:station_distant"] = new JSONValue(this->railway_signal_station_distant);

        if (!this->railway_signal_station_distant_form.empty())
            obj[L"railway:signal:station_distant:form"] = new JSONValue(this->railway_signal_station_distant_form);

        if (!this->railway_signal_traversable_type.empty())
            obj[L"railway:signal:traversable:type"] = new JSONValue(this->railway_signal_traversable_type);

        if (!this->railway_signal_whistle.empty())
            obj[L"railway:signal:whistle"] = new JSONValue(this->railway_signal_whistle);

        if (!this->railway_signal_whistle_form.empty())
            obj[L"railway:signal:whistle:form"] = new JSONValue(this->railway_signal_whistle_form);

        if (!this->railway_signal_wrong_road.empty())
            obj[L"railway:signal:wrong_road"] = new JSONValue(this->railway_signal_wrong_road);

        if (!this->railway_signal_wrong_road_form.empty())
            obj[L"railway:signal:wrong_road:form"] = new JSONValue(this->railway_signal_wrong_road_form);

        if (!this->railway_station_category.empty())
            obj[L"railway:station_category"] = new JSONValue(this->railway_station_category);

        if (!this->railway_switch.empty())
            obj[L"railway:switch"] = new JSONValue(this->railway_switch);

        if (!this->railway_switch_configuration.empty())
            obj[L"railway:switch:configuration"] = new JSONValue(this->railway_switch_configuration);

        if (!this->railway_switch_electric.empty())
            obj[L"railway:switch:electric"] = new JSONValue(this->railway_switch_electric);

        if (!this->railway_switch_movable_frog.empty())
            obj[L"railway:switch:movable_frog"] = new JSONValue(this->railway_switch_movable_frog);

        if (!this->railway_switch_resetting.empty())
            obj[L"railway:switch:resetting"] = new JSONValue(this->railway_switch_resetting);

        if (!this->railway_turnout_side.empty())
            obj[L"railway:turnout_side"] = new JSONValue(this->railway_turnout_side);

        if (!this->razed.empty())
            obj[L"razed"] = new JSONValue(this->razed);

        if (!this->ref.empty())
            obj[L"ref"] = new JSONValue(this->ref);

        if (!this->ref_IFOPT.empty())
            obj[L"ref:IFOPT"] = new JSONValue(this->ref_IFOPT);

        if (!this->ref_station.empty())
            obj[L"ref:station"] = new JSONValue(this->ref_station);

        if (!this->route_ref.empty())
            obj[L"route_ref"] = new JSONValue(this->route_ref);

        if (!this->shelter.empty())
            obj[L"shelter"] = new JSONValue(this->shelter);

        if (!this->source_date.empty())
            obj[L"source:date"] = new JSONValue(this->source_date);

        if (!this->supervised.empty())
            obj[L"supervised"] = new JSONValue(this->supervised);

        if (!this->tactile_paving.empty())
            obj[L"tactile_paving"] = new JSONValue(this->tactile_paving);

        if (!this->tourism.empty())
            obj[L"tourism"] = new JSONValue(this->tourism);

        if (!this->tower_type.empty())
            obj[L"tower:type"] = new JSONValue(this->tower_type);

        if (!this->traffic_calming.empty())
            obj[L"traffic_calming"] = new JSONValue(this->traffic_calming);

        if (!this->traffic_sign.empty())
            obj[L"traffic_sign"] = new JSONValue(this->traffic_sign);

        if (!this->train.empty())
            obj[L"train"] = new JSONValue(this->train);

        if (!this->uic_name.empty())
            obj[L"uic_name"] = new JSONValue(this->uic_name);

        if (!this->uic_ref.empty())
            obj[L"uic_ref"] = new JSONValue(this->uic_ref);

        if (!this->wheelchair.empty())
            obj[L"wheelchair"] = new JSONValue(this->wheelchair);

        if (!this->wheelchair_description.empty())
            obj[L"wheelchair:description"] = new JSONValue(this->wheelchair_description);

        return new JSONValue(obj);
    }
};

#endif // WAYNODE_H