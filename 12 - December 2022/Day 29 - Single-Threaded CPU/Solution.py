class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        next_task, tasks_processing_order = [], []
        curr_time, task_index = 0, 0
        # Sort based on min task processing time or min task index.
        sorted_tasks = [(enqueue, process, idx) for idx, (enqueue, process) in enumerate(tasks)]
        sorted_tasks.sort()
        # Traverse the tasks.
        while task_index < len(tasks) or next_task:
            # Check if the heap is empty.
            if not next_task and curr_time < sorted_tasks[task_index][0]: 
                curr_time = sorted_tasks[task_index][0]
            # Push all the tasks whose 'enqueueTime' less than 'curr_time' into the heap.
            while task_index < len(sorted_tasks) and curr_time >= sorted_tasks[task_index][0]:
                _, process_time, original_index = sorted_tasks[task_index]
                heapq.heappush(next_task, (process_time, original_index))
                task_index += 1
            process_time, index = heapq.heappop(next_task)
            # Complete this task and increment 'curr_time'.
            curr_time += process_time
            tasks_processing_order.append(index)
        return tasks_processing_order