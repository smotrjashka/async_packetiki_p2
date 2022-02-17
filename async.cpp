#include "async.h"
#include "content.h"

#include <vector>
#include <mutex>

namespace async {

    std::vector<content*> contents;
    std::mutex mut;

handle_t connect(std::size_t bulk) {
    content* cont = new content(bulk);
    mut.lock();
    contents.push_back(cont);
    mut.unlock();
    return handle_t(cont->get_ptr());
}

void receive(handle_t handle, const char* data, std::size_t size) {

    (static_cast<content*>(handle))->handle(data, size);

}

void disconnect(handle_t handle) {
    
    std::vector<content*>::iterator iter;
    content* content_to_distroy;
    for (auto i = contents.begin(); i != contents.end(); i++) {
        if (*i == static_cast<content*>(handle)) {
            iter = i;
            content_to_distroy = *i;
            break;
        }
    }

    mut.lock();
    contents.erase(iter);
    mut.unlock();
    content_to_distroy->~content();


}

}
