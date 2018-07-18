#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
// API headers
#include "polysync_core.h"
#include "polysync_node.h"
#include "polysync_sdf.h"
#include "polysync_message.h"
#include "polysync_socket.h"
#include "polysync_node_template.h"

#define unsigned long time_t

#define CCT (+8)
// *****************************************************
// static global types/macros
// *****************************************************

/**
 * @brief Node flags to be OR'd with driver/interface flags.
 *
 * Provided by the compiler so Harbrick can add build-specifics as needed.
 *
 */
#ifndef NODE_FLAGS_VALUE
#define NODE_FLAGS_VALUE (0)
#endif


/**
 * @brief Port number this example connects to.
 *
 */
#define UDP_PORT (9966)

typedef long long ps_ull;
/**
 * @brief IP address this example connects to.
 *
 */
static const char UDP_ADDRESS[] = "127.0.0.1";


/**
 * @brief PolySync node name.
 *
 */
static const char NODE_NAME[] = "polysync-socket-writer-c";



static const char POINTS_MSG_NAME[] = "ps_lidar_points_msg";

static const char OBJECTS_MSG_NAME[] = "ps_objects_msg";

ps_socket *my_socket = NULL;

ps_ull file_number = 0;
ps_ull file_number_object = 0;
char folder_number[] = "008";

static void ps_lidar_points_msg__handler(
        const ps_msg_type msg_type,
        const ps_msg_ref const message,
        void * const user_data );
        
        
static void ps_objects_msg__handler(
        const ps_msg_type msg_type,
        const ps_msg_ref const message,
        void * const user_data );



static int set_configuration(
        ps_node_configuration_data * const node_config );


static void on_init(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );



static void on_release(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );



static void on_error(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );



static void on_fatal(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );



static void on_warn(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );



static void on_ok(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data );






static void ps_objects_msg__handler(
        const ps_msg_type msg_type,
        const ps_msg_ref const message,
        void * const user_data )
{
	// local vars
    int ret = DTC_NONE;
	
	// cast to message
    const ps_objects_msg * const objects_msg = (ps_objects_msg*) message;
    
    time_t rawtime;  
  	struct tm * ptm;  
  	time(&rawtime);  
  	ptm = gmtime(&rawtime);  
  	char file_name[100] = "../data/";
  	sprintf (file_name + 8, "objects/%s/%2d%02d%02d%2d%02d%02d%ld.txt", 
  				folder_number, 
  				ptm->tm_year + 1990,
  				ptm->tm_mon + 1, 
  				ptm->tm_mday,
  				(ptm->tm_hour+CCT)%24, 
  				ptm->tm_min, 
  				ptm->tm_sec,
  				file_number_object
  				); 
 	file_number_object++;			
  	printf("%s\n", file_name);
  	FILE* f = fopen(file_name,"w");
	if (f == NULL)
		printf("file open error\n");

    long objects_index = 0;
    const ps_object *_buffer = objects_msg->objects._buffer;
    
    while( objects_index < objects_msg->objects._length )
    {

        
		fprintf( f,"%16lf\t%016lf\t%016lf\t",
                (double) _buffer[objects_index].position[0],
				(double) _buffer[objects_index].position[1],
				(double) _buffer[objects_index].position[2]);
				
		fprintf(f, "%016lf\t%016lf\t%016lf\n",
                (double) _buffer[objects_index].size[0],
				(double) _buffer[objects_index].size[1],
				(double) _buffer[objects_index].size[2]);
		
		
        objects_index++;
        
    }
	fclose(f);
    	
	
	
}
static void ps_lidar_points_msg__handler(
        const ps_msg_type msg_type,
        const ps_msg_ref const message,
        void * const user_data )
{
    
    // local vars
    int ret = DTC_NONE;
	
	
	time_t rawtime;  
  	struct tm * ptm;  
  	time(&rawtime);  
  	ptm = gmtime(&rawtime);  
  	char file_name[100] = "../data/";
  	sprintf (file_name + 8, "points/%s/%2d%02d%02d%2d%02d%02d%ld.txt", 
  				folder_number,
  				ptm->tm_year + 1990,
  				ptm->tm_mon + 1, 
  				ptm->tm_mday,
  				(ptm->tm_hour+CCT)%24, 
  				ptm->tm_min, 
  				ptm->tm_sec,
  				file_number
  				); 
 	file_number++;			
  	printf("%s\n", file_name);
  	FILE* f = fopen(file_name,"w");
	if (f == NULL)
		printf("file open error\n");
		
    // cast to message
    const ps_lidar_points_msg * const lidar_points_msg = (ps_lidar_points_msg*) message;

    long lidar_points_index = 0;
    // 
    while( lidar_points_index < lidar_points_msg->points._length )
    {

        const ps_lidar_point *_buffer = lidar_points_msg->points._buffer;

				fprintf( f, "%016lf\t%016lf\t%016lf\n",
				(double) _buffer[lidar_points_index].position[0],
				(double) _buffer[lidar_points_index].position[1],
				(double) _buffer[lidar_points_index].position[2]);

	

        lidar_points_index++;
    }
	fclose(f);
    printf( "\n\n\n" );
}


//
static int set_configuration(
        ps_node_configuration_data * const node_config )
{
    // local vars
    ps_socket *socket = NULL;


    // set node configuration default values

    // node type
    node_config->node_type = PSYNC_NODE_TYPE_API_USER;

    // set node domain
    node_config->domain_id = PSYNC_DEFAULT_DOMAIN;

    // set node SDF key
    node_config->sdf_key = PSYNC_SDF_ID_INVALID;

    // set node flags
    node_config->flags = NODE_FLAGS_VALUE | PSYNC_INIT_FLAG_STDOUT_LOGGING;

    // set user data
    node_config->user_data = NULL;

    // set node name
    memset( node_config->node_name, 0, sizeof(node_config->node_name) );
    strncpy( node_config->node_name, NODE_NAME, sizeof(node_config->node_name) );

    // create CAN channel
    if( (socket = malloc( sizeof(*socket) )) == NULL )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- failed to allocate socket data structure",
                __FILE__,
                __LINE__ );

        return DTC_MEMERR;
    }

    // zero
    memset( socket, 0, sizeof(*socket) );

    // set user data pointer to our top-level node data
    // this will get passed around to the various interface routines
    node_config->user_data = (void*) socket;

    return DTC_NONE;
}


//
static void on_init(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    // local vars
    int ret = DTC_NONE;
    ps_socket *socket = NULL;
    ps_msg_type msg_type = PSYNC_MSG_TYPE_INVALID;

    // cast
    socket = (ps_socket*) user_data;

    // check reference since other routines don't
    if( socket == NULL )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- invalid socket",
                __FILE__,
                __LINE__ );

        psync_node_activate_fault( node_ref, DTC_USAGE, NODE_STATE_FATAL );
        return;
    }

    // init UDP socket
    ret = psync_socket_init(
            socket,
            AF_INET,
            SOCK_DGRAM,
            IPPROTO_UDP );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_socket_init returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }

    // set address and port
    ret = psync_socket_set_address(
            socket,
            UDP_ADDRESS,
            UDP_PORT );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_socket_set_address returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }

    // set socket reuse option for multiple connections
    ret = psync_socket_set_reuse_option( socket, 1 );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_socket_set_reuse_option returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }


    my_socket = socket;


    // get objects message type identifier
    ret = psync_message_get_type_by_name(
            node_ref,
            POINTS_MSG_NAME,
            &msg_type );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_message_get_type_by_name returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }
    // register subscriber for objects message
     ret = psync_message_register_listener(
            node_ref,
            msg_type,
            ps_lidar_points_msg__handler,
            NULL );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_message_register_listener returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }
    
    
    
    // get diagnostic trace message type identifier
    ret = psync_message_get_type_by_name(
            node_ref,
            OBJECTS_MSG_NAME,
            &msg_type );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_message_get_type_by_name returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }

    // register subscriber for message
    ret = psync_message_register_listener(
            node_ref,
            msg_type,
            ps_objects_msg__handler,
            NULL );

    // activate fatal error and return if failed
    if( ret != DTC_NONE )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- psync_message_register_listener returned DTC %d",
                __FILE__,
                __LINE__,
                ret );

        psync_node_activate_fault( node_ref, ret, NODE_STATE_FATAL );
        return;
    }
}


//
static void on_release(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    // local vars
    
}


//
static void on_error(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    // do nothing, sleep for 10 milliseconds
    (void) psync_sleep_micro( 10000 );
}


//
static void on_fatal(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    // do nothing, sleep for 10 milliseconds
    (void) psync_sleep_micro( 10000 );
}


//
static void on_warn(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    // do nothing, sleep for 10 milliseconds
    (void) psync_sleep_micro( 10000 );
}


//
static void on_ok(
        ps_node_ref const node_ref,
        const ps_diagnostic_state * const state,
        void * const user_data )
{
    
   ps_socket *socket = NULL;


    // cast
    socket = (ps_socket*) user_data;
    if( socket == NULL )
    {
        psync_log_message(
                LOG_LEVEL_ERROR,
                "%s : (%u) -- invalid socket",
                __FILE__,
                __LINE__ );

        psync_node_activate_fault( node_ref, DTC_USAGE, NODE_STATE_FATAL );
        return;
    }
	#ifdef TEST_OK
		printf("ON_OK is test ok!\n");
	#endif

    // sleep for 1 milliseconds
    (void) psync_sleep_micro( 1000 );


}




// *****************************************************
// public definitions
// *****************************************************

//
int main( int argc, char **argv )
{
    // callback data
    ps_node_callbacks callbacks;


    // zero
    memset( &callbacks, 0, sizeof(callbacks) );

    // set callbacks
    callbacks.set_config = &set_configuration;
    callbacks.on_init = &on_init;
    callbacks.on_release = &on_release;
    callbacks.on_warn = &on_warn;
    callbacks.on_error = &on_error;
    callbacks.on_fatal = &on_fatal;
    callbacks.on_ok = &on_ok;


    // use PolySync main entry, this will give execution context to node template machine
    return( psync_node_main_entry( &callbacks, argc, argv ) );
}
